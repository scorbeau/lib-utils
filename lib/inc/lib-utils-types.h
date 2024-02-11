/*!
 * @file: lib-utils-types.h
 * @date: 2023-12-23
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of common type.
 */
#ifndef LIB_UTILS_TYPES_H__
#define LIB_UTILS_TYPES_H__

#include <stdint.h>

#ifndef _STDINT_H
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int32_t;
typedef signed long long int64_t;
#endif

#ifndef INT8_MIN
#define INT8_MIN    INT8_C(-128)
#endif

#ifndef INT8_MAX
#define INT8_MAX    INT8_C(127)
#endif

#ifndef UINT8_MIN
#define UINT8_MIN   UINT8_C(0)
#endif

#ifndef UINT8_MAX
#define UINT8_MAX   UINT8_C(255)
#endif

#ifndef INT16_MIN
#define INT16_MIN   INT16_C(-32768)
#endif

#ifndef INT16_MAX
#define INT16_MAX   UINT16_C(32767)
#endif

#ifndef UINT16_MIN
#define UINT16_MIN  UINT16_C(0)
#endif

#ifndef UINT16_MAX
#define UINT16_MAX  UINT16_C(65535)
#endif

#ifndef INT32_MIN
#define INT32_MIN   INT32_C(-2147483648)
#endif

#ifndef INT32_MAX
#define INT32_MAX   INT32_C(2147483647)
#endif

#ifndef UINT32_MIN
#define UINT32_MIN  UINT32_C(0)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX  UINT32_C(4294967295)
#endif

#ifndef INT64_MIN
#define INT64_MIN  INT64_C(0)
#endif

#ifndef INT64_MAX
#define INT64_MAX  INT64_C(-9223372036854775808)
#endif

#ifndef UINT64_MIN
#define UINT64_MIN  UINT64_C(9223372036854775807)
#endif

#ifndef UINT64_MAX
#define UINT64_MAX  UINT64_C(18446744073709551615)
#endif

#endif /* LIB_UTILS_TYPES_H__ */
