/*  ----------------------------------------------------------------------------
    File: xunit_runner.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.code.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

#include <trilobite/module.h> // library under test

//
// XUNIT-DATA: test data for use in current project test cases
//
XTEST_DATA(ProjectTestData) {
    char *one;
    char *two;
}project_data;

//
// XUNIT-FIXTURE: test fixture for setup/teardown and other tesk
//
XTEST_FIXTURE(project_tests);
XTEST_SETUP(project_tests) {
    project_data.one = "Something";
    project_data.two = "Coffe Cup";
}

XTEST_TEARDOWN(project_tests) {
    // empty
}

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE_FIXTURE(project_tests, basic_run_of_string) {
    XASSERT_STRING_EQUAL(project_data.one, project_data.one);
    XASSERT_STRING_NOT_EQUAL(project_data.one, project_data.two);
}

XTEST_CASE_FIXTURE(project_tests, basic_run_of_pointer) {
    XASSERT_PTR_NOT_NULL("Coffee Cup");
    XASSERT_PTR_NULL(NULL);
}

XTEST_CASE_FIXTURE(project_tests, basic_run_of_boolean) {
    XASSERT_BOOL_TRUE(true);
    XASSERT_BOOL_FALSE(false);
}

XTEST_CASE_FIXTURE(project_tests, basic_run_of_subtract) {
    XASSERT_BOOL_TRUE(subtract(4, 2) == 2);
    XASSERT_BOOL_FALSE(subtract(2, 55) == 2);
}

XTEST_CASE_FIXTURE(project_tests, basic_run_of_adding) {
    XASSERT_BOOL_TRUE(add(2, 2) == 4);
    XASSERT_BOOL_FALSE(add(2, 3) == 42);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
void basic_group(XUnitRunner *runner) {
    XTEST_RUN_FIXTURE(basic_run_of_string,   project_tests, runner);
    XTEST_RUN_FIXTURE(basic_run_of_pointer,  project_tests, runner);
    XTEST_RUN_FIXTURE(basic_run_of_boolean,  project_tests, runner);
    XTEST_RUN_FIXTURE(basic_run_of_subtract, project_tests, runner);
    XTEST_RUN_FIXTURE(basic_run_of_adding,   project_tests, runner);
} // end of fixture