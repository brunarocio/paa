# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/delio/Delio-Linux-BigInt/BigInt-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/delio/Delio-Linux-BigInt/BigInt-master/build

# Include any dependencies generated for this target.
include CMakeFiles/ConstructorsTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ConstructorsTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ConstructorsTest.dir/flags.make

CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o: CMakeFiles/ConstructorsTest.dir/flags.make
CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o: ../test/constructors/constructors.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o -c /home/delio/Delio-Linux-BigInt/BigInt-master/test/constructors/constructors.cpp

CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delio/Delio-Linux-BigInt/BigInt-master/test/constructors/constructors.cpp > CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.i

CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delio/Delio-Linux-BigInt/BigInt-master/test/constructors/constructors.cpp -o CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.s

CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o.requires:

.PHONY : CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o.requires

CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o.provides: CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o.requires
	$(MAKE) -f CMakeFiles/ConstructorsTest.dir/build.make CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o.provides.build
.PHONY : CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o.provides

CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o.provides.build: CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o


# Object files for target ConstructorsTest
ConstructorsTest_OBJECTS = \
"CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o"

# External object files for target ConstructorsTest
ConstructorsTest_EXTERNAL_OBJECTS =

../bin/ConstructorsTest: CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o
../bin/ConstructorsTest: CMakeFiles/ConstructorsTest.dir/build.make
../bin/ConstructorsTest: lib/libTestRunner.a
../bin/ConstructorsTest: CMakeFiles/ConstructorsTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/ConstructorsTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ConstructorsTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ConstructorsTest.dir/build: ../bin/ConstructorsTest

.PHONY : CMakeFiles/ConstructorsTest.dir/build

CMakeFiles/ConstructorsTest.dir/requires: CMakeFiles/ConstructorsTest.dir/test/constructors/constructors.cpp.o.requires

.PHONY : CMakeFiles/ConstructorsTest.dir/requires

CMakeFiles/ConstructorsTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ConstructorsTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ConstructorsTest.dir/clean

CMakeFiles/ConstructorsTest.dir/depend:
	cd /home/delio/Delio-Linux-BigInt/BigInt-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/delio/Delio-Linux-BigInt/BigInt-master /home/delio/Delio-Linux-BigInt/BigInt-master /home/delio/Delio-Linux-BigInt/BigInt-master/build /home/delio/Delio-Linux-BigInt/BigInt-master/build /home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles/ConstructorsTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ConstructorsTest.dir/depend
