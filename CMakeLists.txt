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

add_subdirectory(googletest) # Add GoogleTest submodule
enable_testing() # Enable testing
set(TEST_FILES # Add the test files from tests dir
    tests/test_Engine.cpp
    #Add additional tests
)
add_executable(SRE2Tests ${TEST_FILES}) # Create the test executable
target_link_libraries(SRE2Tests gtest gtest_main SRE2) # Link Google Test libraries and your library
add_test(NAME SRE2TestSuite COMMAND SRE2Tests) # Add tests

#Link libraries
find_package(SDL2 CONFIG REQUIRED)
    target_link_libraries(SRE2
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    )

find_package(SDL2_ttf CONFIG REQUIRED)
    target_link_libraries(SRE2 PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

find_package(SDL2_mixer CONFIG REQUIRED)
    target_link_libraries(SRE2 PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)

find_package(SDL2_image CONFIG REQUIRED)
    target_link_libraries(SRE2 PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)