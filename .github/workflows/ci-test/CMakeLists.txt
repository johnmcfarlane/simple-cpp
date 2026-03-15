# TODO: Remove version pin (here and in conanfile) once modules support is stable.
cmake_minimum_required(VERSION 4.2.3)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
project(simple-cpp-ci-tests LANGUAGES CXX)

set(CMAKE_CXX_MODULE_STD 1)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

function(add_static_test test_name will_fail)
    add_test(NAME ${test_name}
        COMMAND ${CMAKE_CTEST_COMMAND}
                --build-and-test
                    ${CMAKE_CURRENT_LIST_DIR}/${test_name}
                    ${CMAKE_CURRENT_BINARY_DIR}/${test_name}
                --build-generator ${CMAKE_GENERATOR}
                --build-options
                    "--toolchain=${CMAKE_CURRENT_BINARY_DIR}/../../../conan_toolchain.cmake"
                    "-DCMAKE_CXX_CLANG_TIDY=${CMAKE_CXX_CLANG_TIDY}"
                --test-command ${CMAKE_CTEST_COMMAND}
    )
    set_property(TEST ${test_name} PROPERTY WILL_FAIL ${will_fail})
endfunction()

function(add_dynamic_test test_name will_fail)
    add_executable(${test_name} ${test_name}.cpp)
    add_test(NAME ${test_name} COMMAND ${CMAKE_COMMAND} -E env $<TARGET_FILE:${test_name}>)
    set_property(TEST ${test_name} PROPERTY WILL_FAIL ${will_fail})
endfunction()

# Clang-Tidy checks for use of `goto`
add_static_test(goto $ENV{TRIGGER_CLANG_TIDY})

# Standard library catches UB
add_dynamic_test(vector-overflow $ENV{TRIGGER_STDLIB})

# TSan catches data races
add_dynamic_test(data-race $ENV{TRIGGER_TSAN})

# UBSan catches integer overflow
add_dynamic_test(integer-overflow $ENV{TRIGGER_UBSAN})

# Compiler has elevated/hardened warning levels
add_static_test(unused-label $ENV{TRIGGER_WARNING})
