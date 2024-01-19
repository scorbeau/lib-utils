/*!
 * @file: lib-utils-parse-number.h
 * @date: 2023-01-04
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of function to parse string contains number.
 */
#ifndef LIB_UTILS_PARSE_NUMBER_H__
#define LIB_UTILS_PARSE_NUMBER_H__

#include <stdint.h>

/*!
 * @brief Parse uint8_t from string.
 * @param str       String contains uint8_t to parse.
 * @param number    Pointer to on uint8_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_uint8(const char * str, uint8_t * number);

/*!
 * @brief Parse int8_t from string.
 * @param str       String contains int8_t to parse.
 * @param number    Pointer to on int8_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_int8(const char * str, int8_t * number);

/*!
 * @brief Parse hexadecimal value on uint8_t from string.
 * @param str   String contains hexadecimal value on uint8_t to parse.
 * @param hex   Pointer to on uint8_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_hex8(const char * str, uint8_t * hex);

/*!
 * @brief Parse uint16_t from string.
 * @param str       String contains uint16_t to parse.
 * @param number    Pointer to on uint16_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_uint16(const char * str, uint16_t * number);

/*!
 * @brief Parse int16_t from string.
 * @param str       String contains int16_t to parse.
 * @param number    Pointer to on int16_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_int16(const char * str, int16_t * number);

/*!
 * @brief Parse hexadecimal value on uint16_t from string.
 * @param str   String contains hexadecimal value on uint16_t to parse.
 * @param hex   Pointer to on uint16_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_hex16(const char * str, uint16_t * hex);

/*!
 * @brief Parse uint32_t from string.
 * @param str       String contains uint32_t to parse.
 * @param number    Pointer to on uint32_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_uint32(const char * str, uint32_t * number);

/*!
 * @brief Parse int32_t from string.
 * @param str       String contains int32_t to parse.
 * @param number    Pointer to on int32_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_int32(const char * str, int32_t * number);

/*!
 * @brief Parse hexadecimal value on uint32_t from string.
 * @param str   String contains hexadecimal value on uint32_t to parse.
 * @param hex   Pointer to on uint32_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_hex32(const char * str, uint32_t * hex);

/*!
 * @brief Parse uint64_t from string.
 * @param str       String contains uint64_t to parse.
 * @param number    Pointer to on uint64_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_uint64(const char * str, uint64_t * number);

/*!
 * @brief Parse int64_t from string.
 * @param str       String contains int64_t to parse.
 * @param number    Pointer to on int64_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_int64(const char * str, int64_t * number);

/*!
 * @brief Parse hexadecimal value on uint64_t from string.
 * @param str   String contains hexadecimal value on uint64_t to parse.
 * @param hex   Pointer to on uint64_t to store value.
 * @return 0 on success otherwise -1.
 */
int parse_hex64(const char * str, uint64_t * hex);

#endif /* LIB_UTILS_PARSE_NUMBER_H__ */