cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SRE2)

# Detect and set vcpkg toolchain file
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "vcpkg toolchain file")
endif()


# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type to debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")

# Add library
add_library(SRE2 SHARED 
    src/Engine.cpp)

# Include directories
include_directories(include)

##### GOOGLE TEST #####

add_subdirectory(googletest) # Add GoogleTest submodule
enable_testing() # Enable testing
include_directories(${CMAKE_SOURCE_DIR}/googletest/googlemock/include) #include GoogleMock

     # Function to create a test suite for a class
function(add_test_suite class_name)
     set(test_name "${class_name}Tests")
     add_executable(${test_name} tests/test_${class_name}.cpp)
     target_link_libraries(${test_name} gtest gtest_main SRE2)
     add_test(NAME ${class_name}TestSuite COMMAND ${test_name})
 endfunction()

 add_test_suite(Engine)
 add_test_suite(Scene)


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
    if (WIN32)
        add_custom_command(
            TARGET SRE2 POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:SRE2>"
            VERBATIM
        )
    endif()
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