# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/viggo/source/repos/SRE2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/viggo/source/repos/SRE2/build

# Include any dependencies generated for this target.
include CMakeFiles/SRE2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SRE2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SRE2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SRE2.dir/flags.make

CMakeFiles/SRE2.dir/src/Engine.cpp.obj: CMakeFiles/SRE2.dir/flags.make
CMakeFiles/SRE2.dir/src/Engine.cpp.obj: CMakeFiles/SRE2.dir/includes_CXX.rsp
CMakeFiles/SRE2.dir/src/Engine.cpp.obj: C:/Users/viggo/source/repos/SRE2/src/Engine.cpp
CMakeFiles/SRE2.dir/src/Engine.cpp.obj: CMakeFiles/SRE2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/viggo/source/repos/SRE2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SRE2.dir/src/Engine.cpp.obj"
	C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SRE2.dir/src/Engine.cpp.obj -MF CMakeFiles/SRE2.dir/src/Engine.cpp.obj.d -o CMakeFiles/SRE2.dir/src/Engine.cpp.obj -c C:/Users/viggo/source/repos/SRE2/src/Engine.cpp

CMakeFiles/SRE2.dir/src/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SRE2.dir/src/Engine.cpp.i"
	C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/viggo/source/repos/SRE2/src/Engine.cpp > CMakeFiles/SRE2.dir/src/Engine.cpp.i

CMakeFiles/SRE2.dir/src/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SRE2.dir/src/Engine.cpp.s"
	C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/viggo/source/repos/SRE2/src/Engine.cpp -o CMakeFiles/SRE2.dir/src/Engine.cpp.s

# Object files for target SRE2
SRE2_OBJECTS = \
"CMakeFiles/SRE2.dir/src/Engine.cpp.obj"

# External object files for target SRE2
SRE2_EXTERNAL_OBJECTS =

libSRE2.dll: CMakeFiles/SRE2.dir/src/Engine.cpp.obj
libSRE2.dll: CMakeFiles/SRE2.dir/build.make
libSRE2.dll: CMakeFiles/SRE2.dir/linkLibs.rsp
libSRE2.dll: CMakeFiles/SRE2.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/viggo/source/repos/SRE2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libSRE2.dll"
	"C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f CMakeFiles/SRE2.dir/objects.a
	C:/msys64/ucrt64/bin/ar.exe qc CMakeFiles/SRE2.dir/objects.a @CMakeFiles/SRE2.dir/objects1.rsp
	C:/msys64/ucrt64/bin/c++.exe -g -shared -o libSRE2.dll -Wl,--out-implib,libSRE2.dll.a -Wl,--major-image-version,0,--minor-image-version,0 -Wl,--whole-archive CMakeFiles/SRE2.dir/objects.a -Wl,--no-whole-archive @CMakeFiles/SRE2.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/SRE2.dir/build: libSRE2.dll
.PHONY : CMakeFiles/SRE2.dir/build

CMakeFiles/SRE2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SRE2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SRE2.dir/clean

CMakeFiles/SRE2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/viggo/source/repos/SRE2 C:/Users/viggo/source/repos/SRE2 C:/Users/viggo/source/repos/SRE2/build C:/Users/viggo/source/repos/SRE2/build C:/Users/viggo/source/repos/SRE2/build/CMakeFiles/SRE2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SRE2.dir/depend

