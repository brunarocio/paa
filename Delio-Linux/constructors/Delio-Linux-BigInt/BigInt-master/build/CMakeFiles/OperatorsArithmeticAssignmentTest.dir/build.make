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
include CMakeFiles/OperatorsArithmeticAssignmentTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OperatorsArithmeticAssignmentTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OperatorsArithmeticAssignmentTest.dir/flags.make

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o: CMakeFiles/OperatorsArithmeticAssignmentTest.dir/flags.make
CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o: ../test/operators/arithmetic_assignment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o -c /home/delio/Delio-Linux-BigInt/BigInt-master/test/operators/arithmetic_assignment.cpp

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/delio/Delio-Linux-BigInt/BigInt-master/test/operators/arithmetic_assignment.cpp > CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.i

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/delio/Delio-Linux-BigInt/BigInt-master/test/operators/arithmetic_assignment.cpp -o CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.s

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o.requires:

.PHONY : CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o.requires

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o.provides: CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o.requires
	$(MAKE) -f CMakeFiles/OperatorsArithmeticAssignmentTest.dir/build.make CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o.provides.build
.PHONY : CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o.provides

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o.provides.build: CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o


# Object files for target OperatorsArithmeticAssignmentTest
OperatorsArithmeticAssignmentTest_OBJECTS = \
"CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o"

# External object files for target OperatorsArithmeticAssignmentTest
OperatorsArithmeticAssignmentTest_EXTERNAL_OBJECTS =

../bin/OperatorsArithmeticAssignmentTest: CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o
../bin/OperatorsArithmeticAssignmentTest: CMakeFiles/OperatorsArithmeticAssignmentTest.dir/build.make
../bin/OperatorsArithmeticAssignmentTest: lib/libTestRunner.a
../bin/OperatorsArithmeticAssignmentTest: CMakeFiles/OperatorsArithmeticAssignmentTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/OperatorsArithmeticAssignmentTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OperatorsArithmeticAssignmentTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OperatorsArithmeticAssignmentTest.dir/build: ../bin/OperatorsArithmeticAssignmentTest

.PHONY : CMakeFiles/OperatorsArithmeticAssignmentTest.dir/build

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/requires: CMakeFiles/OperatorsArithmeticAssignmentTest.dir/test/operators/arithmetic_assignment.cpp.o.requires

.PHONY : CMakeFiles/OperatorsArithmeticAssignmentTest.dir/requires

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OperatorsArithmeticAssignmentTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OperatorsArithmeticAssignmentTest.dir/clean

CMakeFiles/OperatorsArithmeticAssignmentTest.dir/depend:
	cd /home/delio/Delio-Linux-BigInt/BigInt-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/delio/Delio-Linux-BigInt/BigInt-master /home/delio/Delio-Linux-BigInt/BigInt-master /home/delio/Delio-Linux-BigInt/BigInt-master/build /home/delio/Delio-Linux-BigInt/BigInt-master/build /home/delio/Delio-Linux-BigInt/BigInt-master/build/CMakeFiles/OperatorsArithmeticAssignmentTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OperatorsArithmeticAssignmentTest.dir/depend
