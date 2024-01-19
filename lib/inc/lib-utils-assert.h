/*!
 * @file: lib-utils-assert.h
 * @date: 2023-12-24
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Declaration of assert macro.
 */
#ifndef LIB_UTILS_ASSERT_H__
#define LIB_UTILS_ASSERT_H__

#include "lib-utils-types.h"

/*!
 * @brief Check 32bits alignment's pointer.
 * @param ptr   Pointer to check.
 */
#define IS_32_BITS_ALIGN( ptr ) ( ( (unsigned long)ptr & 0x3 ) == 0 )

#ifndef DISABLE_PARANOID_MODE

/*!
 * @brief Check if number (num) is in range (between min and max) and return 
 *        with code (ret) if not (or not in int8_t range).
 * @param num   Number to check if it's in range of int8_t and min and max.
 * @param min   Minimum value.
 * @param max   Maximun value.
 * @param ret   Return code value if num not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_I8(num, min, max, ret) \
    do { \
        if((num < INT8_MIN) || (num > INT8_MAX)) { \
            return ret; \
        } else if ((num < min) || (num > max)) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if number (num) is in range (between min and max) and return 
 *        with code (ret) if not (or not in uint8_t range).
 * @param num   Number to check if it's in range of uint8_t and min and max.
 * @param min   Minimum value.
 * @param max   Maximun value.
 * @param ret   Return code value if num not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_U8(num, min, max, ret) \
    do { \
        if((num < UINT8_MIN) || (num > UINT8_MAX)) { \
            return ret; \
        } else if ((num < min) || (num > max)) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if number (num) is in range (between min and max) and return 
 *        with code (ret) if not (or not in int16_t range).
 * @param num   Number to check if it's in range of int16_t and min and max.
 * @param min   Minimum value.
 * @param max   Maximun value.
 * @param ret   Return code value if num not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_I16(num, min, max, ret) \
    do { \
        if((num < INT16_MIN) || (num > INT16_MAX)) { \
            return ret; \
        } else if ((num < min) || (num > max)) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if number (num) is in range (between min and max) and return 
 *        with code (ret) if not (or not in uint16_t range).
 * @param num   Number to check if it's in range of uint16_t and min and max.
 * @param min   Minimum value.
 * @param max   Maximun value.
 * @param ret   Return code value if num not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_U16(num, min, max, ret) \
    do { \
        if((num < UINT16_MIN) || (num > UINT16_MAX)) { \
            return ret; \
        } else if ((num < min) || (num > max)) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if number (num) is in range (between min and max) and return 
 *        with code (ret) if not (or not in int32_t range).
 * @param num   Number to check if it's in range of int32_t and min and max.
 * @param min   Minimum value.
 * @param max   Maximun value.
 * @param ret   Return code value if num not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_I32(num, min, max, ret) \
    do { \
        if((num < INT32_MIN) || (num > INT32_MAX)) { \
            return ret; \
        } else if ((num < min) || (num > max)) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if number (num) is in range (between min and max) and return 
 *        with code (ret) if not (or not in uint32_t range).
 * @param num   Number to check if it's in range of uint32_t and min and max.
 * @param min   Minimum value.
 * @param max   Maximun value.
 * @param ret   Return code value if num not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_U32(num, min, max, ret) \
    do { \
        if((num < UINT32_MIN) || (num > UINT32_MAX)) { \
            return ret; \
        } else if ((num < min) || (num > max)) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if number (num) is in range (between min and max) and return 
 *        with code (ret) if not (or not in int64_t range).
 * @param num   Number to check if it's in range of int64_t and min and max.
 * @param min   Minimum value.
 * @param max   Maximun value.
 * @param ret   Return code value if num not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_I64(num, min, max, ret) \
    do { \
        if((num < INT64_MIN) || (num > INT64_MAX)) { \
            return ret; \
        } else if ((num < min) || (num > max)) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if number (num) is in range (between min and max) and return 
 *        with code (ret) if not (or not in uint64_t range).
 * @param num   Number to check if it's in range of uint64_t and min and max.
 * @param min   Minimum value.
 * @param max   Maximun value.
 * @param ret   Return code value if num not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_U64(num, min, max, ret) \
    do { \
        if((num < UINT64_MIN) || (num > UINT64_MAX)) { \
            return ret; \
        } else if ((num < min) || (num > max)) { \
            return ret; \
        } \
    } while (0);


/*!
 * @brief Check if c-string (str) is not NULL pointer and not empty and return 
 *        with code (ret) if not.
 * @param str   C string to check.
 * @param ret   Return code value if str not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_STR_NOT_NULL(str, ret) \
    do { \
        if((! str) || (0 == str[0])) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if pointer (ptr) is not NULL pointer return with code (ret) if 
 *        not.
 * @param ptr   Pointer to check.
 * @param ret   Return code value if str not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_PTR(ptr, ret) \
    do { \
        if(! ptr) { \
            return ret; \
        } \
    } while (0);

/*!
 * @brief Check if pointer (ptr) is not NULL pointer and 32 bit aligned return
 *        with code (ret) if not.
 * @param ptr   Pointer to check.
 * @param ret   Return code value if str not matched.
 * @return ret in case of error otherwise not return.
 */
#define ASSERT_PTR32(ptr, ret) \
    do { \
        if(! ptr) { \
            return ret; \
        } else if (! IS_32_BITS_ALIGN(ptr)) { \
            return ret; \
        } \
    } while (0);

#else /* !DISABLE_PARANOID_MODE */

#define ASSERT_I8(num, min, max, ret)
#define ASSERT_U8(num, min, max, ret)
#define ASSERT_I16(num, min, max, ret)
#define ASSERT_U16(num, min, max, ret)
#define ASSERT_I32(num, min, max, ret)
#define ASSERT_U32(num, min, max, ret)

#define ASSERT_STR_NOT_NULL(str, ret)

#define ASSERT_PTR(ptr, ret)

#define ASSERT_PTR32(ptr, ret)

#endif

#endif /* LIB_UTILS_ASSERT_H__ */