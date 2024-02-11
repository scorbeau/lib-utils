/*!
 * @file: lib-utils-version.h
 * @date: 2023-12-20
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of library version management functions.
 */
#ifndef LIB_UTILS_VERSION_H__
#define LIB_UTILS_VERSION_H__

/*!
 * @brief Return library name.
 * @return The library name when available otherwise "NO_LIBRARY_NAME_DEFINED".
 */
const char * get_lib_utils_name(void);

/*!
 * @brief Return GIT tag version of lib-utils.
 * @return The GIT tag revision when available otherwise "NO_GIT_TAG_DEFINED".
 */
const char * get_lib_utils_version(void);

/*!
 * @brief Return GIT sha1 value of lib-utils.
 * @return The GIT sha1 value when available otherwise "NO_GIT_SHA1_DEFINED".
 */
const char * get_lib_utils_git_sha1(void);

/*!
 * @brief Return the date of lib-utils compilation.
 * @return The date of lib-utils compilation.
 */
const char * get_lib_utils_compilation_date(void);

/*!
 * @brief Return the time of lib-utils compilation.
 * @return The time of lib-utils compilation.
 */
const char * get_lib_utils_compilation_time(void);

/*!
 * @brief Display the library version on stdout.
 * @return None.
 */
void print_lib_utils_informations(void);

#endif /* LIB_UTILS_VERSION_H__ */