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
include CMakeFiles/OperatorsIOStreamTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OperatorsIOStreamTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OperatorsIOStreamTest.dir/flags.make

CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o: CMakeFiles/OperatorsIOStreamTest.dir/flags.make
CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o: ../test/operators/io_stream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o -c /home/delio/Delio-Linux-BigInt/BigInt-master/test/operators/io_stream.cpp

CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delio/Delio-Linux-BigInt/BigInt-master/test/operators/io_stream.cpp > CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.i

CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delio/Delio-Linux-BigInt/BigInt-master/test/operators/io_stream.cpp -o CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.s

CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o.requires:

.PHONY : CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o.requires

CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o.provides: CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o.requires
	$(MAKE) -f CMakeFiles/OperatorsIOStreamTest.dir/build.make CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o.provides.build
.PHONY : CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o.provides

CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o.provides.build: CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o


# Object files for target OperatorsIOStreamTest
OperatorsIOStreamTest_OBJECTS = \
"CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o"

# External object files for target OperatorsIOStreamTest
OperatorsIOStreamTest_EXTERNAL_OBJECTS =

../bin/OperatorsIOStreamTest: CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o
../bin/OperatorsIOStreamTest: CMakeFiles/OperatorsIOStreamTest.dir/build.make
../bin/OperatorsIOStreamTest: lib/libTestRunner.a
../bin/OperatorsIOStreamTest: CMakeFiles/OperatorsIOStreamTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/OperatorsIOStreamTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OperatorsIOStreamTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OperatorsIOStreamTest.dir/build: ../bin/OperatorsIOStreamTest

.PHONY : CMakeFiles/OperatorsIOStreamTest.dir/build

CMakeFiles/OperatorsIOStreamTest.dir/requires: CMakeFiles/OperatorsIOStreamTest.dir/test/operators/io_stream.cpp.o.requires

.PHONY : CMakeFiles/OperatorsIOStreamTest.dir/requires

CMakeFiles/OperatorsIOStreamTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OperatorsIOStreamTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OperatorsIOStreamTest.dir/clean

CMakeFiles/OperatorsIOStreamTest.dir/depend:
	cd /home/delio/Delio-Linux-BigInt/BigInt-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/delio/Delio-Linux-BigInt/BigInt-master /home/delio/Delio-Linux-BigInt/BigInt-master /home/delio/Delio-Linux-BigInt/BigInt-master/build /home/delio/Delio-Linux-BigInt/BigInt-master/build /home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles/OperatorsIOStreamTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OperatorsIOStreamTest.dir/depend
