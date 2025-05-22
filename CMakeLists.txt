cmake_minimum_required(VERSION 3.15)
project(banking LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable coverage
option(ENABLE_COVERAGE "Enable coverage reporting" ON)
if(ENABLE_COVERAGE)
    add_compile_options(--coverage -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage -fprofile-arcs)
endif()

# Find GTest and GMock
find_package(GTest REQUIRED)
include(GoogleTest)

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
    test/main.cpp
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
target_link_libraries(banking_test PRIVATE
    banking
    GTest::GTest
    GTest::Main
    gmock
)

# Automatically discover and add tests
gtest_discover_tests(banking_test
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    TEST_PREFIX "Tests: "
)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Install targets (optional)
install(TARGETS banking
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
