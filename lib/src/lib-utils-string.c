/*!
 * @file: lib-utils-parse-string.c
 * @date: 2024-02-05
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of function to manage string.
 */
#include <stdlib.h>
#include <string.h>

#include "lib-utils-assert.h"

char * allocate_and_copy_string( const char * str)
{
    char * ret = NULL;

    ASSERT_STR_NOT_NULL(str, NULL);

    ret = malloc( strlen( str ) + 1 );

    if(ret)
    {
        strcpy(ret, str);
    }

    return ret;
}

char * allocate_and_concat_string( const char * str1, const char * str2 )
{
    char * ret = NULL;

    ASSERT_STR_NOT_NULL(str1, NULL);
    ASSERT_STR_NOT_NULL(str2, NULL);

    ret = malloc( strlen( str1 ) + strlen( str2 ) + 1 );

    if(ret)
    {
        strcpy( ret, str1 );
        strcat( ret, str2 );
    }

    return ret;
}