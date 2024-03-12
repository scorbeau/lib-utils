/*!
 * @file: lib-utils-version.h
 * @date: 2023-12-20
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of library version management functions.
 */

#include <stdio.h>

#include "lib-utils-version.h"

#if __has_include( "lib-utils-git-informations.h" )
#include "lib-utils-git-informations.h"
#endif

#ifndef GIT_TAG
/*!
 * @brief Default git tag version.
 */
#define GIT_TAG "NO_GIT_TAG_DEFINED"
#endif

#ifndef GIT_SHA1
/*!
 * @brief Default git sha1 value.
 */
#define GIT_SHA1 "NO_GIT_SHA1_DEFINED"
#endif

#ifndef LIB_NAME
/*!
 * @brief Default library name value.
 */
#define LIB_NAME "NO_LIBRARY_NAME_DEFINED"
#endif

const char * get_lib_utils_name(void)
{
    return LIB_NAME;
}

const char * get_lib_utils_version(void)
{
    return GIT_TAG;
}

const char * get_lib_utils_git_sha1(void)
{
    return GIT_SHA1;
}

const char * get_lib_utils_compilation_date(void)
{
    return __DATE__;
}

const char * get_lib_utils_compilation_time(void)
{
    return __TIME__;
}

void print_lib_utils_informations(void)
{
    printf("Library informations:\r\n");
    printf(" * Name : %s\r\n", LIB_NAME);
    printf(" * Git tag : %s\r\n", GIT_TAG);
    printf(" * Git sha1 : %s\r\n", GIT_SHA1);
    printf(" * Compilation date : %s@%s\r\n", __DATE__, __TIME__);
}