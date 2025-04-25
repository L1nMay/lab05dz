cmake_minimum_required(VERSION 3.15)
project(banking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GTest
find_package(GTest REQUIRED)

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
    test/main.cpp # Add main.cpp to the list of test files
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
# Add test to CTest
add_test(NAME banking_tests COMMAND banking_test)

# Coverage
if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    set_target_properties(banking_test PROPERTIES
        CXX_FLAGS "-fprofile-arcs -ftest-coverage"
        LINK_FLAGS "-fprofile-arcs -ftest-coverage"
    )
endif()
