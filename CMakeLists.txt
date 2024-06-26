cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SRE2)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add library
add_library(SRE2 SHARED src/Engine.cpp)

# Include directories
include_directories(include)

## GOOGLE TEST ##

# Add GoogleTest submodule
add_subdirectory(googletest)

# Enable testing
enable_testing()

# Add the test files from tests dir
set(TEST_FILES
    tests/test_Engine.cpp
    #Add additional tests
)

# Create the test executable
add_executable(SRE2Tests ${TEST_FILES})

# Link Google Test libraries and your library
target_link_libraries(SRE2Tests gtest gtest_main SRE2)

# Add tests
add_test(NAME SRE2TestSuite COMMAND SRE2Tests)