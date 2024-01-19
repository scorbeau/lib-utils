/*!
 * @file: test-lib-utils-parse-number.cpp
 * @date: 2024-01-06
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of unit test for library version management functions.
 */
#include <gtest/gtest.h>

extern "C"
{
    #include "lib-utils-parse-number.h"
}

namespace
{
    // Tests parse_uint8 -> Valid case
    TEST( parse_uint8, valid_cases )
    {
        int ret;
        uint8_t number = -1;

        ret = parse_uint8("12", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 12);

        ret = parse_uint8("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0);
        
        ret = parse_uint8("255", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ( number, 255 );
    }

    // Tests parse_uint8 -> Invalid case
    TEST( parse_uint8, invalid_cases )
    {
        int ret;
        uint8_t number = -1;

        ret = parse_uint8(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint8("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint8("-1", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_uint8("256", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_uint8("ab", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint8("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint8("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

    // Tests parse_int8 -> Valid case
    TEST( parse_int8, valid_cases )
    {
        int ret;
        int8_t number = -1;

        ret = parse_int8("12", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 12);

        ret = parse_int8("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0);

        ret = parse_int8("-1", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, -1);
        
        ret = parse_int8("-128", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, -128);

        ret = parse_int8("127", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 127);
    }

    // Tests parse_int8 -> Invalid case
    TEST( parse_int8, invalid_cases )
    {
        int ret;
        int8_t number = -1;

        ret = parse_int8(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int8("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_int8("-129", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_int8("128", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_int8("ab", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int8("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int8("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

    // Tests parse_hex8 -> Valid case
    TEST( parse_hex8, valid_cases )
    {
        int ret;
        uint8_t number = -1;

        ret = parse_hex8("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x00);

        ret = parse_hex8("0x00", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x00);

        ret = parse_hex8("0xFF", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0xFF);

        ret = parse_hex8("0x42", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x42);

        ret = parse_hex8("0xA5", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0xA5 );

        ret = parse_hex8("5A", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x5A);
    }

    // Tests parse_hex8 -> Invalid case
    TEST( parse_hex8, invalid_cases )
    {
        int ret;
        uint8_t number = -1;

        ret = parse_hex8(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex8("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex8("0x100", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_hex8("100", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_hex8("Oxab", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex8("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex8("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

        // Tests parse_uint16 -> Valid case
    TEST( parse_uint16, valid_cases )
    {
        int ret;
        uint16_t number = -1;

        ret = parse_uint16("42", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 42);

        ret = parse_uint16("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0);
        
        ret = parse_uint16("65535", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 65535);
    }

    // Tests parse_uint16 -> Invalid case
    TEST( parse_uint16, invalid_cases )
    {
        int ret;
        uint16_t number = -1;

        ret = parse_uint16(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint16("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint16("-1", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_uint16("65536", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_uint16("abcd", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint16("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint16("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

    // Tests parse_int16 -> Valid case
    TEST( parse_int16, valid_cases )
    {
        int ret;
        int16_t number = -1;

        ret = parse_int16("12", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 12);

        ret = parse_int16("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0);

        ret = parse_int16("-1", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, -1);
        
        ret = parse_int16("-32768", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, -32768);

        ret = parse_int16("32767", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 32767);
    }

    // Tests parse_int16 -> Invalid case
    TEST( parse_int16, invalid_cases )
    {
        int ret;
        int16_t number = -1;

        ret = parse_int16(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int16("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_int16("-32769", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_int16("32768", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_int16("abcd", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int16("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int16("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

    // Tests parse_hex16 -> Valid case
    TEST( parse_hex16, valid_cases )
    {
        int ret;
        uint16_t number = -1;

        ret = parse_hex16("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x00);

        ret = parse_hex16("0x0000", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x0000);

        ret = parse_hex16("0xFFFF", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0xFFFF);

        ret = parse_hex16("0x4242", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x4242);

        ret = parse_hex16("0x55AA", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x55AA );

        ret = parse_hex16("55AA", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x55AA);
    }

    // Tests parse_hex16 -> Invalid case
    TEST( parse_hex16, invalid_cases )
    {
        int ret;
        uint16_t number = -1;

        ret = parse_hex16(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex16("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex16("0x10000", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_hex16("10000", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_hex16("Oxabcd", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex16("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex16("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

        // Tests parse_uint32 -> Valid case
    TEST( parse_uint32, valid_cases )
    {
        int ret;
        uint32_t number = -1;

        ret = parse_uint32("42", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 42);

        ret = parse_uint32("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0);
        
        ret = parse_uint32("4294967295", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 4294967295);
    }

    // Tests parse_uint32 -> Invalid case
    TEST( parse_uint32, invalid_cases )
    {
        int ret;
        uint32_t number = -1;

        ret = parse_uint32(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint32("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint32("-1", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_uint32("4294967296", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_uint32("abcdef01", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint32("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint32("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

    // Tests parse_int32 -> Valid case
    TEST( parse_int32, valid_cases )
    {
        int ret;
        int32_t number = -1;

        ret = parse_int32("12", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 12);

        ret = parse_int32("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0);

        ret = parse_int32("-1", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, -1);
        
        ret = parse_int32("-2147483648", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, -2147483648);

        ret = parse_int32("2147483647", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 2147483647);
    }

    // Tests parse_int32 -> Invalid case
    TEST( parse_int32, invalid_cases )
    {
        int ret;
        int32_t number = -1;

        ret = parse_int32(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int32("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_int32("-2147483649", &number);
        printf("NUmber : %d\r\n", number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_int32("2147483648", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_int32("abcdef01", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int32("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int32("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

    // Tests parse_hex32 -> Valid case
    TEST( parse_hex32, valid_cases )
    {
        int ret;
        uint32_t number = -1;

        ret = parse_hex32("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x00);

        ret = parse_hex32("0x00000000", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x0000);

        ret = parse_hex32("0xFFFFFFFF", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0xFFFFFFFF);

        ret = parse_hex32("0x42424242", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x42424242);

        ret = parse_hex32("0x5555AAAA", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x5555AAAA );

        ret = parse_hex32("5555AAAA", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x5555AAAA);
    }

    // Tests parse_hex32 -> Invalid case
    TEST( parse_hex32, invalid_cases )
    {
        int ret;
        uint32_t number = -1;

        ret = parse_hex32(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex32("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex32("0x100000000", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex32("100000000", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_hex32("Oxabcdef01", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex32("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex32("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

        // Tests parse_uint64 -> Valid case
    TEST( parse_uint64, valid_cases )
    {
        int ret;
        uint64_t number = -1;

        ret = parse_uint64("42", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 42);

        ret = parse_uint64("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0);
        
        ret = parse_uint64("18446744073709551615", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, UINT64_C(18446744073709551615));
    }

    // Tests parse_uint64 -> Invalid case
    TEST( parse_uint64, invalid_cases )
    {
        int ret;
        uint64_t number = -1;

        ret = parse_uint64(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint64("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint64("-1", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_uint64("18446744073709551616", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_uint64("abcdef01abcdef01", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint64("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_uint64("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

    // Tests parse_int64 -> Valid case
    TEST( parse_int64, valid_cases )
    {
        int ret;
        int64_t number = -1;

        ret = parse_int64("12", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 12);

        ret = parse_int64("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0);

        ret = parse_int64("-1", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, -1);
        
        ret = parse_int64("-9223372036854775808", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, INT64_MIN);

        ret = parse_int64("9223372036854775807", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 9223372036854775807);
    }

    // Tests parse_int64 -> Invalid case
    TEST( parse_int64, invalid_cases )
    {
        int ret;
        int64_t number = -1;

        ret = parse_int64(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int64("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_int64("-9223372036854775809", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_int64("9223372036854775808", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_int64("abcdef01abcdef01", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int64("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_int64("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }

    // Tests parse_hex64 -> Valid case
    TEST( parse_hex64, valid_cases )
    {
        int ret;
        uint64_t number = -1;

        ret = parse_hex64("0", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x00);

        ret = parse_hex64("0x0000000000000000", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x0000);

        ret = parse_hex64("0xFFFFFFFFFFFFFFFF", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0xFFFFFFFFFFFFFFFF);

        ret = parse_hex64("0x4242424242424242", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x4242424242424242);

        ret = parse_hex64("0x55555555AAAAAAAA", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x55555555AAAAAAAA );

        ret = parse_hex64("55555555AAAAAAAA", &number);
        ASSERT_EQ( ret, 0 );
        ASSERT_EQ(number, 0x55555555AAAAAAAA);
    }

    // Tests parse_hex64 -> Invalid case
    TEST( parse_hex64, invalid_cases )
    {
        int ret;
        uint64_t number = -1;

        ret = parse_hex64(NULL, &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex64("42", NULL);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex64("0x10000000000000000", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_hex64("10000000000000000", &number);
        ASSERT_EQ( ret, -1 );
        
        ret = parse_hex64("Oxabcdef01abcdef01", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex64("", &number);
        ASSERT_EQ( ret, -1 );

        ret = parse_hex64("helloworld", &number);
        ASSERT_EQ( ret, -1 );
    }
}

int main( int argc, char** argv )
{
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}