/*!
 * @file: version.h
 * @date: 2024-02-08
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of application version.
 */
#ifndef VERSION_H__
#define VERSION_H__

#if __has_include( "git-informations.h" )
#include "git-informations.h"
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

#ifndef APPL_NAME
/*!
 * @brief Default application name value.
 */
#define APPL_NAME "NO_APPLICATION_NAME_DEFINED"
#endif

#endif /* VERSION_H__ */