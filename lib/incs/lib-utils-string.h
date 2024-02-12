/*!
 * @file: lib-utils-string.h
 * @date: 2024-02-05
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of function prototype to manage string.
 */
#ifndef LIB_UTILS_STRING_H__
#define LIB_UTILS_STRING_H__

#define _STRINGIFY_1( str )   #str
#define _STRINGIFY( x )       _STRINGIFY_1( x )

/*!
 * @brief Allocate and copy string (user must free returned string when not 
 *        used).
 * @param str   String to copy.
 * @return The copy of the string on success otherwise NULL.
 */
char * allocate_and_copy_string( const char * str);

/*!
 * @brief Allocate and concat two strings str1 and str2 (user must free returned
 *        string when not used).
 * @param str1  Base string .
 * @param str2  String to concat.
 * @return The string concat on success otherwise NULL.
 */
char * allocate_and_concat_string( const char * str1, const char * str2 );

#endif /* LIB_UTILS_STRING_H__ */