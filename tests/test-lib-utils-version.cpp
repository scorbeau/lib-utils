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
    // Tests get_lib_utils_name
    TEST( get_lib_utils_name, valid_cases )
    {
        EXPECT_STREQ( LIB_NAME, get_lib_utils_name() );
    }

    // Tests get_lib_utils_version
    TEST( get_lib_utils_version, valid_cases )
    {
        EXPECT_STREQ( GIT_TAG, get_lib_utils_version() );
    }

    // Tests get_lib_utils_git_sha1
    TEST( get_lib_utils_git_sha1, valid_cases )
    {
        EXPECT_STREQ( GIT_SHA1, get_lib_utils_git_sha1() );
    }
}

int main( int argc, char** argv )
{
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}