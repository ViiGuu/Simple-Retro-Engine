cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SRE2)

# Detect and set vcpkg toolchain file
#if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "vcpkg toolchain file")
#endif()


# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add library
add_library(SRE2 SHARED 
    src/Engine.cpp)

# Include directories
include_directories(include)

##### GOOGLE TEST #####

    add_subdirectory(googletest) # Add GoogleTest submodule
    enable_testing() # Enable testing

    set(TEST_FILES # Add the test files here
        tests/test_Engine.cpp
        #Add additional tests
    )
    add_executable(SRE2Tests ${TEST_FILES}) # Create the test executable
    target_link_libraries(SRE2Tests gtest gtest_main SRE2) # Link Google Test libraries and your library
    add_test(NAME SRE2TestSuite COMMAND SRE2Tests) # Add tests


##### INCLUDE AND LINK LIBRARIES #####
# Set target_link_libraries to PUBLIC to avoid #include errors

    find_package(SDL2 CONFIG REQUIRED)
    if(SDL2_FOUND)
        target_link_libraries(SRE2
                PUBLIC
                $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
                $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        )
        message(STATUS "SDL2 found!")
    else()
        message(FATAL_ERROR "SDL2 not found!")
    endif()

    find_package(SDL2_ttf CONFIG REQUIRED)
    if(SDL2_ttf_FOUND)
        target_link_libraries(SRE2 PUBLIC $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)
        message(STATUS "SDL2_ttf found!")
    else()
        message(FATAL_ERROR "SDL2_ttf not found!")
    endif()

    find_package(SDL2_mixer CONFIG REQUIRED)
    if(SDL2_mixer_FOUND)
        target_link_libraries(SRE2 PUBLIC $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)
        message(STATUS "SDL2_mixer found!")
    else()
        message(FATAL_ERROR "SDL2_mixer not found!")
    endif()

    find_package(SDL2_image CONFIG REQUIRED)
    if(SDL2_image_FOUND)
        target_link_libraries(SRE2 PUBLIC $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
        message(STATUS "SDL2_image found!")
    else()
            message(FATAL_ERROR "SDL2_image not found!")
        endif()