/*!
 * @file: lib-utils-list.h
 * @date: 2024-01-26
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of list macro.
 */
#ifndef LIB_UTILS_LIST_H__
#define LIB_UTILS_LIST_H__

/*!
 * @brief Compute the number of element in table.
 * @param tab   Table to get the number of element.
 * @return The number of element of table.
 */
#define GET_NB_ELEMENTS( tab ) ( sizeof( tab ) / sizeof( tab[0] ) )

#endif /* LIB_UTILS_LIST_H__ */