/*!
 * @file: test-lib-utils-version.cpp
 * @date: 2023-12-20
 * @author: Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)
 * @brief: Implementation of unit test for library version management functions.
 */
#include <gtest/gtest.h>

#if __has_include( "git-informations.h" )
    #include "git-informations.h"
#endif

extern "C"
{
    #include "lib-utils-version.h"
}

namespace
{
    // Tests getLibName
    TEST( getLibName, valid_cases )
    {
        EXPECT_STREQ( LIB_NAME, getLibName() );
    }

    // Tests getLibUtilsVersion
    TEST( getLibUtilsVersion, valid_cases )
    {
        EXPECT_STREQ( GIT_TAG, getLibUtilsVersion() );
    }

    // Tests getLibUtilsSha1
    TEST( getLibUtilsSha1, valid_cases )
    {
        EXPECT_STREQ( GIT_SHA1, getLibUtilsSha1() );
    }
}

int main( int argc, char** argv )
{
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}