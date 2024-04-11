/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <fossil/module.h> // library under test

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST(lib_subtract_case) {
    TEST_ASSUME_TRUE(subtract(4, 2) == 2);
    TEST_ASSUME_FALSE(subtract(2, 55) == 2);
}

XTEST(lib_add_case) {
    TEST_ASSUME_TRUE(add(2, 2) == 4);
    TEST_ASSUME_FALSE(add(2, 3) == 42);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(basic_group) {
    XTEST_RUN_UNIT(lib_subtract_case);
    XTEST_RUN_UNIT(lib_add_case);
} // end of fixture