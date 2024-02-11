/*!
 * @file: params-desc.c
 * @date: 2024-01-01
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of parameters descriptions.
 */
#include <stdio.h>

#include <lib-utils-tab.h>

#include "params-desc.h"

/*!
 * @brief Parameters description.
 */
const struct parameter_description_t g_parameters_description[] =
{
    {
        .type = BOOL_TYPE,
        .offset = offsetof(struct params_t, display_help),
        .size = sizeof(bool),
        .arg_shortname = 'h',
        .arg_longname = "help",
        .help = "Display help."
    },
    {
        .type = BOOL_TYPE,
        .offset = offsetof(struct params_t, display_version),
        .size = sizeof(bool),
        .arg_shortname = 'v',
        .arg_longname = "version",
        .help = "Display version."
    },
    {
        .type = SENTINEL_TYPE,
        .offset = -1,
        .size = -1,
        .arg_shortname = -1,
        .help = NULL,
    },
};

const char * g_application_description = "Skeleton test application.";

/*!
 * @brief Default parameters values.
 */
struct params_t g_default_parameters =
{
    .display_help = false,
    .display_version = false,
} ;

uint32_t get_number_parameters( void )
{
    return ( sizeof( g_parameters_description ) > 0 ) ? \
            GET_NB_ELEMENTS( g_parameters_description ) : 0;
}

void display_parameters_help( const char * application_name )
{
    uint32_t nb_parameters;
    uint32_t i;

    nb_parameters = get_number_parameters() - 1;
    
    printf("%s - %s\r\n", application_name, g_application_description );

    printf("Usage : %s [", application_name );
    for(i=0; i<nb_parameters; i++)
    {
        printf( "%c", g_parameters_description[i].arg_shortname );

        if( BOOL_TYPE != g_parameters_description[i].type )
        {
            printf(":");
        }
    }
    printf("]\r\n");

    for(i=0; i<nb_parameters; i++)
    {
        printf(" - %c/%s\t%s\r\n", \
                g_parameters_description[i].arg_shortname, \
                g_parameters_description[i].arg_longname, \
                g_parameters_description[i].help );
    }
}
