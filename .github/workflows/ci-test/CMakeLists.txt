cmake_minimum_required(VERSION 4.2.1)
project(simple-cpp-ci-tests LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

function(setup_control_test_properties test_name will_fail)
    # Test for the expected exit status.
    set_property(TEST ${test_name} PROPERTY WILL_FAIL ${will_fail})
endfunction()

function(add_control_test fault_name)
    add_test(NAME ${fault_name}
        COMMAND ${CMAKE_CTEST_COMMAND}
                --build-and-test
                    ${CMAKE_CURRENT_LIST_DIR}/${fault_name}
                    ${CMAKE_CURRENT_BINARY_DIR}/${fault_name}
                --build-generator ${CMAKE_GENERATOR}
                --build-noclean
                --build-options
                    --toolchain=${CMAKE_CURRENT_BINARY_DIR}/../../../conan_toolchain.cmake
                    "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
                    "-DCMAKE_CXX_CLANG_TIDY=${CMAKE_CXX_CLANG_TIDY}"
                --test-command ${fault_name})
endfunction()

# Test a static analyser check.
function(add_static_control_tests fault_name will_fail)
    add_control_test(${fault_name})

    setup_control_test_properties(${fault_name} ${will_fail})
endfunction()

# Test a dynamic analyser check.
function(add_dynamic_control_tests fault_name will_fail)
    add_control_test(${fault_name} ${fault_name})

    setup_control_test_properties(${fault_name} ${will_fail})
endfunction()

# TSan catches a data race.
add_dynamic_control_tests(data-race $ENV{TRIGGER_TSAN} "data race")

# The Sandard Library catches a buffer overflow.
add_dynamic_control_tests(vector-overflow $ENV{TRIGGER_STDLIB} "Illegal instruction|index out of bounds|Assertion .*size.* failed")

# UBSan catches an integer overflow.
add_dynamic_control_tests(integer-overflow $ENV{TRIGGER_UBSAN} "Illegal instruction|signed integer overflow")

# Clang-Tidy catches a use of `goto`.
add_static_control_tests(goto $ENV{TRIGGER_CLANG_TIDY} "avoid using 'goto' for flow control")

# The compiler catches an unused label.
add_static_control_tests(unused-label $ENV{TRIGGER_WARNING} "my_unused_label")
