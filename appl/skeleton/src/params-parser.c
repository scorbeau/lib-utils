/*!
 * @file: params-parser.h
 * @date: 2023-12-24
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of parameters parser functions.
 */
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#include <lib-utils-assert.h>
#include <lib-utils-list.h>
#include <lib-utils-parse-number.h>
#include <lib-utils-string.h>

#include "params-desc.h"

/*!
 * @brief Set parameter value to params struct.
 * @param shortname Short name of parameter option in command line.
 * @param value     String contains parameters value (NULL if option has not
 *                  parameters value).
 * @param params    Pointer on struct with parameters to init.
 * @return 0 on success otherwise -1.
 */
static int set_param_value( char shortname,
                            const char * value,
                            struct params_t * params);

/*!
 * @brief Get option string parameter optstring for function getopt_long and 
 *        getopt. (User must free return string when no used anymore).
 * @return Allocate optstring to pass to getopt or getopt_long on success 
 *         otherwise NULL.
 */
static char * get_opt_string( void );

/*!
 * @brief Get option list for getopt_long function. (User must free return 
 *        string when no used anymore).
 * @return Allocate optstring to pass to getopt or getopt_long on success 
 *         otherwise NULL.
 */
static struct option * get_opt_list( void );

int parse_application_parameters(int argc, char ** argv, struct params_t *params)
{
    int ret = -1;
    int c;
    struct option * p_lopts;
    char *opt_str;
    int opt_idx = 0;

    ASSERT_I32( argc, 1, INT32_MAX, -1 );
    ASSERT_PTR( argv, -1 );
    ASSERT_PTR( params, -1 );

    memcpy(params, &g_default_parameters, sizeof(*params) );

    p_lopts = get_opt_list();
    opt_str = get_opt_string();

    if(p_lopts && opt_str)
    {
        ret = 0;

        while ( 0 == ret )
        {
            c = getopt_long( argc, argv, opt_str, p_lopts, &opt_idx );

            if ( -1 == c )
            {
                break;
            }
            else
            {
                if(required_argument == p_lopts[opt_idx].has_arg)
                {
                    ret = set_param_value( ( char )c, \
                                            optarg, \
                                            params );
                }
                else
                {
                    ret = set_param_value( ( char )c, \
                                            NULL, \
                                            params );
                }
            }
        }
    }

    if(p_lopts)
    {
        free(p_lopts);
    }

    if(opt_str)
    {
        free(opt_str);
    }

    return ret;
}

int set_param_value( char shortname,
                     const char * value,
                     struct params_t * params)
{
    int ret = 0;
    int i = 0;
    bool found = false;
    uint8_t *ptr8;

    ASSERT_PTR(params, -1);

    while((0 == ret) && !found && (SENTINEL_TYPE != g_parameters_description[i].type))
    {
        if(g_parameters_description[i].arg_shortname == shortname)
        {
            found = true;
            ptr8 = &((uint8_t*)params)[g_parameters_description[i].offset];
            switch(g_parameters_description[i].type)
            {
                case U8_TYPE:
                    ret = parse_uint8( value , ptr8 );
                break;
                case I8_TYPE:
                    ret = parse_int8( value , (int8_t*) ptr8 );
                break;
                case HEX8_TYPE:
                    ret = parse_uint8( value , ptr8 );
                break;
                case U16_TYPE:
                    ret = parse_uint16( value , (uint16_t*) ptr8 );
                break;
                case I16_TYPE:
                    ret = parse_int16( value , (int16_t*) ptr8 );
                break;
                case HEX16_TYPE:
                    ret = parse_hex16( value , (uint16_t*) ptr8 );
                break;
                case U32_TYPE:
                    ret = parse_uint32( value , (uint32_t*) ptr8 );
                break;
                case I32_TYPE:
                    ret = parse_int32( value , (int32_t*) ptr8 );
                break;
                case HEX32_TYPE:
                    ret = parse_hex32( value , (uint32_t*) ptr8 );
                break;
                case U64_TYPE:
                    ret = parse_uint64( value , (uint64_t*) ptr8 );
                break;
                case I64_TYPE:
                    ret = parse_int64( value , (int64_t*) ptr8 );
                break;
                case HEX64_TYPE:
                    ret = parse_hex64( value , (uint64_t*) ptr8 );
                break;
                case DFLOAT_TYPE:
                    ret = parse_double( value, (double *) ptr8 );
                break;
                case STR_TYPE:
                    ptr8 = (uint8_t*) allocate_and_copy_string( value );
                break;
                case BOOL_TYPE:
                    *((bool*)ptr8) = true;
                break;
                case CHAR_TYPE:
                    *ptr8 = value[0];
                break;
                default:
                    ret = -1;
                break;
            }
        }
        i++;
    }

    if( ! found )
    {
        ret = -1;
    }

    return ret;
}

char * get_opt_string( void )
{
    uint32_t nb_elements;
    uint32_t i;
    uint32_t j;
    char * str = NULL;

    nb_elements = get_number_parameters();

    /* Double elements and alloc to store param list */
    str = malloc( nb_elements * 2 );
    if( str )
    {
        i = 0;
        j = 0;

        while( SENTINEL_TYPE != g_parameters_description[i].type )
        {
            str[j] = g_parameters_description[i].arg_shortname;

            if( BOOL_TYPE != g_parameters_description[i].type )
            {
                str[j+1] = ':';
                j++;
            }
            j++;
            i++;
        }

        str[j] = '\0';
    }

    return str;
}

struct option * get_opt_list( void )
{
    struct option * lopts = NULL;
    uint32_t nb_elements;
    uint32_t i;

    nb_elements = get_number_parameters();

    lopts = malloc( nb_elements * sizeof( struct option ) );
    if( lopts )
    {
        i = 0;

        while( SENTINEL_TYPE != g_parameters_description[i].type )
        {
            lopts[i].name = g_parameters_description[i].arg_longname;
            lopts[i].has_arg = ( BOOL_TYPE != g_parameters_description[i].type ) ?
                    required_argument : no_argument;
            lopts[i].flag = 0;
            lopts[i].val = g_parameters_description[i].arg_shortname;
            i++;
        }

        lopts[i].name = NULL;
        lopts[i].has_arg = 0;
        lopts[i].flag = 0;
        lopts[i].val = 0;
    }

    return lopts;
}