/*!
 * @file: lib-utils-logger.h
 * @date: 2023-12-20
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of functions and logger macros.
 */
#ifndef LIB_UTILS_LOGGER_H__
#define LIB_UTILS_LOGGER_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE /* For: ", ##" */
#endif

#include <errno.h>
#include <stdio.h>
#if __has_include( <syslog.h> )
#include <syslog.h>
#endif

/*!
 * @enum log_level_t
 * @brief Enum log level.
 */
typedef enum
{
    LEVEL_UNKNOWN = -1, /*!< Level unknown. */
    LEVEL_TRACE   = 0,  /*!< Trace log level. */
    LEVEL_DEBUG   = 1,  /*!< Debug log level. */
    LEVEL_INFO    = 2,  /*!< Information log level. */
    LEVEL_NOTICE  = 3,  /*!< Notice log level. */
    LEVEL_WARNING = 4,  /*!< Warning log level. */
    LEVEL_ERROR   = 5,  /*!< Error (recoverable) log level. */
    LEVEL_FATAL   = 6,  /*!< Error (fatal) log level. */
    NB_LOG_LEVEL,       /*!< Number of log level. */
} log_level_t;

/* Only if logger is required */
#if defined( DISABLE_LOG )
#define TRACE_LOG( msg_fmt, ... )
#define DEBUG_LOG( msg_fmt, ... )
#define INFO_LOG( msg_fmt, ... )
#define NOTICE_LOG( msg_fmt, ... )
#define WARNING_LOG( msg_fmt, ... )
#define ERROR_LOG( msg_fmt, ... )
#define FATAL_LOG( msg_fmt, ... )
#define BUFFER_MSG_LOG( l, m, b, s )
#define ASCII_MSG_LOG( lvl, pre, str, sz )
#define ERRNO_MSG_LOG( msg_fmt, ... )
#define BACKTRACE()
#else

/*!
 * @enum log_mode_t
 * @brief Writing log mode.
 */
typedef enum
{
    MODE_CONSOLE = 0,   /*!< Print log in console. */
    MODE_FILE,          /*!< Print to file. */ 
#ifdef _SYS_SYSLOG_H
    MODE_SYSLOG,        /*!< Print log to syslog. */
#endif
    MODE_NO_LOG,        /*!< No log. */
} log_mode_t;

#if 0
/*!
 * @brief Thread name.
 */
extern __thread char* g_logger_thread_name;
#endif

/*!
 * @brief Handle to log file
 */
extern FILE* g_dbg_file;

/*!
 * @brief Get log level.
 * @return log level.
 */
log_level_t get_log_level( void );

/*!
 * @brief Get log mode.
 *
 * @return log mode.
 */
log_mode_t get_log_mode( void );

/*!
 * @brief Get log level as string.
 * @param [in]  level   Level code from log_level_t list.
 *
 * @return Log level name on success otherwise "UNKNOWN".
 */
const char* get_log_level_str( int level );

/*!
 * @brief Get log mode as string.
 * @return Log mode name on success otherwise NULL.
 */
const char* get_log_mode_str( void );

/*!
 * @brief Function to print a buffer in hexadecimal.
 * @param [in]  file    Filename where log is coming.
 * @param [in]  line    Line in file as string where log is coming.
 * @param [in]  func    Function name where log is coming.
 * @param [in]  lvl     Log level (See log_level_t).
 * @param [in]  msg     Prefix message to log.
 * @param [in]  buff    Buffer to log in hexadecimal.
 * @param [in]  size    Size of buffer.
 * @return None.
 */
void print_log_buff( const char*          file,
                     const char*          line,
                     const char*          func,
                     int                  lvl,
                     const char*          msg,
                     const unsigned char* buff,
                     int                  size );

/*!
 * @brief Function to print ASCII message (no ASCII character is remplaced by 
 *        '.').
 * @param [in]  file    Filename where log is coming.
 * @param [in]  line    Line in file as string where log is coming.
 * @param [in]  func    Function name where log is coming.
 * @param [in]  lvl     Log level (See log_level_t).
 * @param [in]  msg     Prefix message to log.
 * @param [in]  buff    Buffer to log in ASCII.
 * @param [in]  size    Size of buffer.
 * @return None.
 */
void print_log_msg( const char* file,
                    const char* line,
                    const char* func,
                    int         lvl,
                    const char* msg,
                    const char* buff,
                    int         size );

#define _STR( str )           #str
#define _XSTR( str )          _STR( str )
#define _LOG_LVL( lvl )       LEVEL_##lvl
#define _XLOG_LVL( lvl )      _LOG_LVL( lvl )

/*!
 * @brief Define critical log.
 */
#define LOG_FATAL             LOG_CRIT

/*!
 * @brief Define debug log.
 */
#define LOG_TRACE             LOG_DEBUG

/*!
 * @brief Define error log.
 */
#define LOG_ERROR             LOG_ERR

#ifdef _SYS_SYSLOG_H
#define SYSLOG_CASE else if ( get_log_mode() == MODE_SYSLOG )                  \
        {                                                                      \
            if ( get_log_level() <= _XLOG_LVL( lvl ) )                         \
            {                                                                  \
                syslog( LOG_##lvl,                                             \
                        "<%s> " __FILE__                                       \
                        "(" _XSTR( __LINE__ ) "):%s: " msg_fmt,                \
                        program_invocation_short_name,                         \
                        __func__,                                              \
                        ##__VA_ARGS__ );                                       \
            }                                                                  \
        }
#else
#define SYSLOG_CASE
#endif

/*!
 * @brief Message log macro
 * @param [in] lvl      Level of log, must be:
 *                       - TRACE
 *                       - DEBUG
 *                       - INFO
 *                       - NOTICE
 *                       - WARNING
 *                       - ERROR
 *                       - FATAL.
 * @param [in] msg_fmt  Message.
 */
#define LOG( lvl, msg_fmt, ... )                                               \
    do                                                                         \
    {                                                                          \
        if ( get_log_mode() == MODE_CONSOLE )                                  \
        {                                                                      \
            if ( get_log_level() <= _XLOG_LVL( lvl ) )                         \
            {                                                                  \
                fprintf( stdout,                                               \
                         "[" #lvl "]:<%s> "__FILE__"(" _XSTR( __LINE__ ) "):%s"\
                         ": " msg_fmt "\n",                                    \
                         program_invocation_short_name,                        \
                         __func__,                                             \
                         ##__VA_ARGS__ );                                      \
                fflush( stdout );                                              \
            }                                                                  \
        }                                                                      \
        else if( get_log_mode() == MODE_FILE )                                 \
        {                                                                      \
            if ( ( g_dbg_file != NULL ) &&                                     \
                 ( get_log_level() <= _XLOG_LVL( lvl ) ) )                     \
            {                                                                  \
                fprintf( g_dbg_file,                                           \
                         "[" #lvl "]:<%s> "__FILE__"(" _XSTR( __LINE__ ) "):%s"\
                         ": " msg_fmt "\n",                                    \
                         program_invocation_short_name,                        \
                         __func__,                                             \
                         ##__VA_ARGS__ );                                      \
                fflush( g_dbg_file );                                          \
            }                                                                  \
        }                                                                      \
        SYSLOG_CASE                                                            \
    } while ( 0 )

/*!
 * @brief Trace log message.
 * @param [in] msg_fmt [char*] Message
 */
#define TRACE_LOG( msg_fmt, ... )                                              \
    LOG( TRACE, msg_fmt, ##__VA_ARGS__ )

/*!
 * @brief Debug log message.
 * @param [in] msg_fmt [char*] Message
 */
#define DEBUG_LOG( msg_fmt, ... )                                              \
    LOG( DEBUG, msg_fmt, ##__VA_ARGS__ )

/*!
 * @brief Info log message.
 * @param [in] msg_fmt [char*] Message
 */
#define INFO_LOG( msg_fmt, ... )                                               \
    LOG( INFO, msg_fmt, ##__VA_ARGS__ )

/*!
 * @brief Notice log message.
 * @param [in] msg_fmt [char*] Message
 */
#define NOTICE_LOG( msg_fmt, ... )                                             \
    LOG( NOTICE, msg_fmt, ##__VA_ARGS__ )

/*!
 * @brief Warning log message.
 * @param [in] msg_fmt [char*] Message
 */
#define WARNING_LOG( msg_fmt, ... )                                            \
    LOG( WARNING, msg_fmt, ##__VA_ARGS__ )

/*!
 * @brief Error log message.
 * @param [in] msg_fmt [char*] Message
 */
#define ERROR_LOG( msg_fmt, ... )                                              \
    LOG( ERROR, msg_fmt, ##__VA_ARGS__ )

/*!
 * @brief Fatal log message.
 * @param [in] msg_fmt [char*] Message
 */
#define FATAL_LOG( msg_fmt, ... )                                              \
    LOG( FATAL, msg_fmt, ##__VA_ARGS__ )

/*!
 * @brief Log error with errno.
 * @param [in] msg_fmt [char*] Message
 */
#define ERRNO_MSG_LOG( msg_fmt, ... )                                          \
    do                                                                         \
    {                                                                          \
        ERROR( msg_fmt " - (%d: %m)", ##__VA_ARGS__, errno );                  \
        errno = 0;                                                             \
    } while ( 0 )

/*!
 * @brief Function to print buffer in hex.
 * @param [in]  l       See log_level_t
 * @param [in]  m       Message prefixe to print.
 * @param [in]  b       Buffer to display in hexadecimal.
 * @param [in]  s       Size of buffer to display in hexadecimal.
 */
#define BUFFER_MSG_LOG( l, m, b, s )                                           \
    print_log_buff( __FILE__,                                                  \
                    _XSTR( __LINE__ ),                                         \
                    __func__,                                                  \
                    l,                                                         \
                    m,                                                         \
                    (unsigned char*)b,                                         \
                    s )

/*!
 * @brief Function to print buffer in hex.
 * @param [in]  lvl       See log_level_t
 * @param [in]  pre       Message prefixe to print.
 * @param [in]  str       Buffer to display in ascii.
 * @param [in]  sz        Size of buffer to display in ascii.
 */
#define ASCII_MSG_LOG( lvl, pre, str, sz )                                     \
    print_log_msg( __FILE__,                                                   \
                   _XSTR( __LINE__ ),                                          \
                   __func__,                                                   \
                   lvl,                                                        \
                   pre,                                                        \
                   (char*)str,                                                 \
                   sz )

#endif /* ! DISABLE_LOG */

#endif /* LIB_UTILS_LOGGER_H__ */
