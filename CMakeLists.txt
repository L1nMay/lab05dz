cmake_minimum_required(VERSION 3.15)
project(banking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к GTest (для Windows)
if(WIN32)
    set(GTEST_INCLUDE_DIR $ENV{GTEST_ROOT})
    set(GTEST_LIBRARY C:/ProgramData/chocolatey/lib/gtest/lib/gtest.lib) #путь до gtest.lib
    set(GTEST_MAIN_LIBRARY C:/ProgramData/chocolatey/lib/gtest/lib/gtest_main.lib) #путь до gtest_main.lib
endif()

# Find GTest
include(FindGTest)
if (NOT GTest_FOUND)
    message(FATAL_ERROR "GTest not found, please set GTEST_ROOT variable")
endif()

# Source files
set(SOURCE_FILES
    src/Account.cpp
    src/Transaction.cpp
)

# Header files
set(HEADER_FILES
    include/Account.h
    include/Transaction.h
)

# Test files
set(TEST_FILES
    test/AccountTest.cpp
    test/TransactionTest.cpp
)

# Library
add_library(banking ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(banking PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Tests
enable_testing()
add_executable(banking_test ${TEST_FILES})
target_link_libraries(banking_test banking GTest::GTest GTest::Main)
add_test(NAME banking_tests COMMAND banking_test)

# Coverage
if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -fprofile-arcs -ftest-coverage")
endif()
