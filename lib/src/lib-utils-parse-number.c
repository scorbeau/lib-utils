/*!
 * @file: lib-utils-parse-number.c
 * @date: 2024-01-04
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of function to parse string contains number.
 */
#include <stdlib.h>

#include "lib-utils-assert.h"
#include "lib-utils-parse-number.h"

int parse_uint8(const char * str, uint8_t * num)
{
    int             ret;
    char*           end;
    unsigned long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( num, -1 );

    tmp = strtoul( str, &end, 10 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( tmp > UINT8_MAX )
    {
        ret = -1;
    }
    else
    {
        *num = (uint8_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_int8(const char * str, int8_t * num)
{
    int    ret;
    char*  end;
    long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( num, -1 );

    tmp = strtol( str, &end, 10 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( ( tmp > INT8_MAX ) || ( tmp < INT8_MIN ) )
    {
        ret = -1;
    }
    else
    {
        *num = (int8_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_hex8(const char * str, uint8_t * hex)
{
    int             ret;
    char*           end;
    unsigned long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( hex, -1 );

    tmp = strtoul( str, &end, 16 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( tmp > UINT8_MAX )
    {
        ret = -1;
    }
    else
    {
        *hex = (uint8_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_uint16(const char * str, uint16_t * num)
{
    int    ret;
    char*  end;
    unsigned long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( num, -1 );

    tmp = strtoul( str, &end, 10 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( tmp > UINT16_MAX )
    {
        ret = -1;
    }
    else
    {
        *num = (uint16_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_int16(const char * str, int16_t * num)
{
    int    ret;
    char*  end;
    long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( num, -1 );

    tmp = strtol( str, &end, 10 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( ( tmp > INT16_MAX ) || ( tmp < INT16_MIN ) )
    {
        ret = -1;
    }
    else
    {
        *num = (int16_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_hex16(const char * str, uint16_t * hex)
{
    int             ret;
    char*           end;
    unsigned long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( hex, -1 );

    tmp = strtoul( str, &end, 16 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( tmp > UINT16_MAX )
    {
        ret = -1;
    }
    else
    {
        *hex = (uint16_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_uint32(const char * str, uint32_t * num)
{
    int    ret;
    char*  end;
    unsigned long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( num, -1 );

    tmp = strtoul( str, &end, 10 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( tmp > UINT32_MAX )
    {
        ret = -1;
    }
    else
    {
        *num = (uint32_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_int32(const char * str, int32_t * num)
{
    int    ret;
    char*  end;
    int64_t tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( num, -1 );

    tmp = strtoll( str, &end, 10 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( ( tmp > INT32_MAX ) || ( tmp < INT32_MIN ) )
    {
        ret = -1;
    }
    else
    {
        *num = (int32_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_hex32(const char * str, uint32_t * hex)
{
    int             ret;
    char*           end;
    unsigned long long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( hex, -1 );

    tmp = strtoull( str, &end, 16 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( tmp > UINT32_MAX )
    {
        ret = -1;
    }
    else
    {
        *hex = (uint32_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_uint64(const char * str, uint64_t * num)
{
    int    ret;
    char*  end;
    unsigned long long  tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( num, -1 );

    tmp = strtoull( str, &end, 10 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( tmp > UINT64_MAX )
    {
        ret = -1;
    }
    else
    {
        *num = (uint64_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_int64(const char * str, int64_t * num)
{
    int    ret;
    char*  end;
    long long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( num, -1 );

    tmp = strtoll( str, &end, 10 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( ( tmp > INT64_MAX ) || ( tmp < INT64_MIN ) )
    {
        ret = -1;
    }
    else
    {
        *num = (int64_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_hex64(const char * str, uint64_t * hex)
{
    int             ret;
    char*           end;
    unsigned long long   tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( hex, -1 );

    tmp = strtoull( str, &end, 16 );

    if ( *end )
    {
        ret = -1;
    }
    else if ( tmp > UINT64_MAX )
    {
        ret = -1;
    }
    else
    {
        *hex = (uint64_t)tmp;
        ret = 0;
    }

    return ret;
}

int parse_double(const char * str, double * number)
{
    int     ret;
    char*   end;
    double  tmp;

    ASSERT_STR_NOT_NULL( str, -1 );
    ASSERT_PTR( number, -1 );

    tmp = strtod( str, &end );

    if ( *end )
    {
        ret = -1;
    }
    else
    {
        *number = tmp;
        ret = 0;
    }

    return ret;
}
