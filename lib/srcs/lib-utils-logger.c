/*!
 * @file: lib-utils-logger.h
 * @date: 2023-03-02
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of functions and logger macros.
 */
/* Compile only log are enabled. */
#ifndef DISABLE_LOG

#define _GNU_SOURCE   
#include <errno.h>

#include <stdlib.h>
#include <string.h>

#include "lib-utils-logger.h"

/*!
 * @brief Default log level (WARNING).
 */
#define DEFAULT_LOG_LEVEL       LEVEL_WARNING

/*!
 * @brief Default log mode (No log).
 */
#define DEFAULT_LOG_MODE         MODE_NO_LOG

/*!
 * @brief Default log file name.
 */
#define DEFAULT_LOG_FILE        "log.txt"

/*!
 * @struct log_level_to_str_t
 * @brief Associate log level to string.
 */
struct log_level_to_str_t
{
    char*       name;       /*!< Log level name. */
    log_level_t level;      /*!< Log level value. */
#if defined(_SYS_SYSLOG_H)
    int         syslog;     /*!< Syslog level value. */
#endif
};

/*!
 * @struct log_mode_to_str_t
 * @brief Associate log mode to string.
 */
struct log_mode_to_str_t
{
        char*      name; /*< Log mode name. */
        log_mode_t mode; /*< Log mode value. */
};

#if 0
/*!
 * @brief Contains the program short name.
 */
extern char* program_invocation_short_name;

/*!
 * @brief Define application name.
 */
const char* g_appl_name = program_invocation_short_name;
#endif

/*!
 * @brief Define current log level.
 */
static log_level_t s_log_level = DEFAULT_LOG_LEVEL;

/*!
 * @brief Define current log mode.
 */
static log_mode_t s_log_mode = DEFAULT_LOG_MODE;

/*!
 * @brief Log mode to string.
 */
const struct log_mode_to_str_t log_mode_to_str[] = {
    {
      .name = "CONSOLE",
      .mode = MODE_CONSOLE,
    },
    {
      .name = "console",
      .mode = MODE_CONSOLE,
    },
    {
      .name = "file",
      .mode = MODE_FILE,
    },
    {
      .name = "FILE",
      .mode = MODE_FILE,
    },
#if defined(_SYS_SYSLOG_H)
    {
      .name = "SYSLOG",
      .mode = MODE_SYSLOG,
    },
    {
      .name = "syslog",
      .mode = MODE_SYSLOG,
    },
#endif
    {
      .name = NULL,
      .mode = -1,
    },
};

/*!
 * @brief Associate log level to string.
 */
const struct log_level_to_str_t log_level_to_str[] = {
    {
        .name   = "TRACE",
        .level  = LEVEL_TRACE,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_DEBUG,
#endif
    },
    {
        .name   = "trace",
        .level  = LEVEL_TRACE,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_DEBUG,
#endif
    },
    {
        .name   = "DEBUG",
        .level  = LEVEL_DEBUG,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_DEBUG,
#endif
    },
    {
        .name   = "debug",
        .level  = LEVEL_DEBUG,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_DEBUG,
#endif
    },
    {
        .name   = "INFO",
        .level  = LEVEL_INFO,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_INFO,
#endif
    },
    {
        .name   = "info",
        .level  = LEVEL_INFO,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_INFO,
#endif
    },
    {
        .name   = "NOTICE",
        .level  = LEVEL_NOTICE,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_NOTICE,
#endif
    },
    {
        .name   = "notice",
        .level  = LEVEL_NOTICE,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_NOTICE,
#endif
    },
    {
        .name   = "WARN",
        .level  = LEVEL_WARNING,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_WARNING,
#endif
    },
    {
        .name   = "warn",
        .level  = LEVEL_WARNING,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_WARNING,
#endif
    },
    {
        .name   = "ERROR",
        .level  = LEVEL_ERROR,
    #if defined(_SYS_SYSLOG_H)
        .syslog = LOG_ERR,
#endif
    },
    {
        .name   = "error",
        .level  = LEVEL_ERROR,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_ERR,
#endif
    },
    {
        .name   = "FATAL",
        .level  = LEVEL_FATAL,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_CRIT,
#endif
    },
    {
        .name   = "fatal",
        .level  = LEVEL_FATAL,
#if defined(_SYS_SYSLOG_H)
        .syslog = LOG_CRIT,
#endif
    },
    {
        .name   = NULL,
        .level  = LEVEL_UNKNOWN,
#if defined(_SYS_SYSLOG_H)
        .syslog = -1,
#endif
    }
};

/*!
 * @brief Handle to log file.
 */
static FILE* s_log_file = NULL;

/*!
 * @brief Init log system with LOG_LEVEL and LOG_MODE environment variables
 *        allows user to configure log system. (Automaticly call on startup)
 * @return None.
 */
__attribute__( ( constructor ) ) static void initialize_logger()
{
#if defined(_SYS_SYSLOG_H)
    int   syslog_lvl = LOG_WARNING; /* By default log warning */
#endif
    int   i;
    char* level = getenv( "LOG_LEVEL" );
    char* mode  = getenv( "LOG_MODE" );

    i = 0;
    while ( ( ! mode ) && ( ! log_mode_to_str[i].name ) )
    {
        if ( 0 == strcmp( mode, log_mode_to_str[i].name ) )
        {
            s_log_mode = log_mode_to_str[i].mode;
        }
        i++;
    }

    i = 0;
    while ( ( level != NULL ) && ( log_level_to_str[i].name != NULL ) )
    {
        if ( 0 == strcmp( level, log_level_to_str[i].name ) )
        {
            s_log_level = log_level_to_str[i].level;
#if defined(_SYS_SYSLOG_H)
            if ( s_log_mode == MODE_SYSLOG )
            {
                syslog_level = log_level_to_str[i].syslog;
            }
#endif
        }
        i++;
    }

    switch( s_log_mode )
    {
        case MODE_FILE:
            s_log_file = fopen( DEFAULT_LOG_FILE, "a" );
        break;
#if defined(_SYS_SYSLOG_H)
        case MODE_SYSLOG:
            setlogmask( LOG_UPTO( syslog_level ) );
            openlog( program_invocation_short_name,
                    LOG_CONS | LOG_PID | LOG_NDELAY,
                    LOG_DAEMON );
        break;
#endif
        default:
            /* Nothing todo */
        break;
    }
}

/*!
 * @brief Release logger (close syslog if is installed and initialized) or close
 *        log file.
 * @return None.
 */
__attribute__( ( destructor ) ) static void release_logger()
{
#if defined(_SYS_SYSLOG_H)
    if ( s_log_mode == MODE_SYSLOG )
    {
        closelog();
    }
#endif

    if ( s_log_file )
    {
        fclose( s_log_file );
        s_log_file = NULL;
    }
}

log_level_t get_log_level()
{
    return s_log_level;
}

log_mode_t get_log_mode()
{
    return s_log_mode;
}

const char* get_log_level_str( int level )
{
    int i = 0;

    while ( log_level_to_str[i].name != NULL &&
            log_level_to_str[i].level != level )
    {
        i++;
    }

    return log_level_to_str[i].name ? log_level_to_str[i].name : "UNKNONW";
}

const char* get_log_mode_str( void )
{
    int i = 0;

    while ( ( log_mode_to_str[i].name != NULL ) &&
            ( log_mode_to_str[i].mode != s_log_mode ) )
    {
        i++;
    }

    return log_mode_to_str[i].name;
}

#if defined(_SYS_SYSLOG_H)
static int get_syslog_level_value( int level )
{
    int i = 0;

    while ( log_level_to_str[i].name != NULL &&
            log_level_to_str[i].level != level )
    {
        i++;
    }

    return log_level_to_str[i].name ? log_level_to_str[i].syslog
                                    : LOG_DEBUG;
}
#endif

static void log_message( int level, const char* message )
{
    if ( get_log_level() <= level )
    {
        switch(get_log_mode())
        {
            case MODE_CONSOLE:
                fprintf( stdout, message );
                fflush( stdout );
            break;
        
            case MODE_FILE:
                if ( s_log_file )
                {
                    fprintf( s_log_file, message );
                    fflush( s_log_file );
                }
            break;

#if defined(_SYS_SYSLOG_H)
            case MODE_SYSLOG:
                syslog( get_syslog_level_value( level ), message );
            break;
#endif

            default:
                /* Nothing to do. */
            break;
        }
    }
}

static char* get_allocated_log_message( const char* file,
                                        const char* line,
                                        const char* func,
                                        int         lvl,
                                        const char* msg,
                                        int         bufferSize )
{
    char* ret = NULL;

    bufferSize += 1;  /* Add "[""*/
    bufferSize += strlen( get_log_level_str( lvl ) );
    bufferSize += 3;  /* Add "]:<" */

    if(program_invocation_short_name)
    {
        bufferSize += strlen( program_invocation_short_name );
    }

    bufferSize += 2; /* Add "> " */
    if ( file )
    {
        bufferSize += strlen( file );
    }
    bufferSize += 1; /* Add "(" */

    if ( line )
    {
        bufferSize += strlen( line );
    }
    bufferSize += 2; /* Add "):" */

    if ( func )
    {
        bufferSize += strlen( func );
    }
    bufferSize += 2; /* Add ": " */

    if ( msg )
    {
        bufferSize += strlen( msg );
    }

    bufferSize += 3; /* Add ":\n\0" */

    ret = malloc( bufferSize );
    if ( ret )
    {
        memset( ret, 0, bufferSize );

        snprintf( ret,
                  bufferSize - 1,
                  "[%s]:<%s> %s(%s):%s: %s:\n",
                  get_log_level_str( lvl ),
                  program_invocation_short_name ? 
                        program_invocation_short_name : "",
                  file ? file : "",
                  line ? line : "",
                  func ? func : "",
                  msg ? msg : "" );
    }

    return ret;
}

void print_log_buff( const char*          file,
                     const char*          line,
                     const char*          func,
                     int                  lvl,
                     const char*          msg,
                     const unsigned char* buffer,
                     int                  size )
{
    int   i;
    char* str      = NULL;
    char  tmp[10]  = { '\0' };
    int   strMaxSz = ( size * 4 ) + 2 + 2;

    str = get_allocated_log_message( file, line, func, lvl, msg, strMaxSz );
    if ( NULL != str )
    {
        for ( i = 0; i < size; i++ )
        {
            if ( !( i & 0xF ) )
            {
                strncat( str, "\n", strMaxSz );
            }
            snprintf( tmp, sizeof( tmp ), "%02X ", buffer[i] );
            strncat( str, tmp, strMaxSz );
            memset( tmp, '\0', sizeof( tmp ) );
        }
        strncat( str, "\n", strMaxSz );

        log_message( lvl, str );

        free( str );
    }
}

void print_log_msg( const char* file,
                    const char* line,
                    const char* func,
                    int         lvl,
                    const char* msg,
                    const char* buffer,
                    int         size )
{
    int   i;
    char* str      = NULL;
    char  tmp[20]  = { '\0' };
    int   strMaxSz = ( size * 6 ) + 2 + 2;
    int   index    = 0;

    str = get_allocated_log_message( file, line, func, lvl, msg, strMaxSz );
    if ( NULL != str )
    {
        index = strlen( str );

        for ( i = 0; i < size; i++ )
        {
            if ( ( buffer[i] >= 0x20 ) && ( buffer[i] < 0x7F ) )
            {
                str[index] = buffer[i];
                index++;
            }
            else
            {
                snprintf( tmp, sizeof( tmp ), "<%02X>", buffer[i] );
                index += strlen( tmp );
                strncat( str, tmp, strMaxSz );
            }
        }
        strncat( str, "\n", strMaxSz );

        log_message( lvl, str );

        free( str );
    }
}

#endif /* DISABLE_LOG */
