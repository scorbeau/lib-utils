/*!
 * @file: main.c
 * @date: 2023-12-23
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of application skeleton to test one module of lib.
 */
#include <stdio.h>

#include <lib-utils-string.h>
#include <lib-utils-version.h>

#include "params-desc.h"
#include "params-parser.h"
#include "version.h"

#ifndef APPL_NAME
#define APPL_NAME   "skeleton"
#endif

/*!
 * @brief Application entry point
 * @param argc  Argument counter.
 * @param argv  Argument values.
 * @return 0 on success otherwise -1.
*/
int main (int argc, char** argv)
{
    int ret = 1;
    struct params_t appl_params;

    if(-1 == parse_application_parameters( argc, argv, &appl_params ) )
    {
        printf("Error invalid parameter parsing.\r\n");
        ret = 1;
    }
    else if( appl_params.display_help )
    {
        display_parameters_help( _STRINGIFY( APPL_NAME ) );
        ret = 0;
    }
    else if( appl_params.display_version )
    {
        printf("%s Version %s (%s)\r\n",
                _STRINGIFY( APPL_NAME ),
                GIT_TAG,
                GIT_SHA1 );
        printf("Skeleton to test %s version %s\r\n", \
                get_lib_utils_name(), \
                get_lib_utils_version() );
        printf("Library compiled %s at %s\r\n", \
                get_lib_utils_compilation_date(), \
                get_lib_utils_compilation_time() );
        printf("Application compiled %s at %s\r\n", __DATE__, __TIME__);
        ret = 0;
    }
    else
    {
        printf("Nothing to do.\r\n");
        ret = 0;
    }

    return ret;
}
