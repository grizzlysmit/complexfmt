# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/grizzlysmit/Projects/C++/complexfmt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/grizzlysmit/Projects/C++/complexfmt/build

# Include any dependencies generated for this target.
include CMakeFiles/testcmplx.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testcmplx.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testcmplx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testcmplx.dir/flags.make

CMakeFiles/testcmplx.dir/testcmplx.cpp.o: CMakeFiles/testcmplx.dir/flags.make
CMakeFiles/testcmplx.dir/testcmplx.cpp.o: /home/grizzlysmit/Projects/C++/complexfmt/testcmplx.cpp
CMakeFiles/testcmplx.dir/testcmplx.cpp.o: CMakeFiles/testcmplx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grizzlysmit/Projects/C++/complexfmt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testcmplx.dir/testcmplx.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testcmplx.dir/testcmplx.cpp.o -MF CMakeFiles/testcmplx.dir/testcmplx.cpp.o.d -o CMakeFiles/testcmplx.dir/testcmplx.cpp.o -c /home/grizzlysmit/Projects/C++/complexfmt/testcmplx.cpp

CMakeFiles/testcmplx.dir/testcmplx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testcmplx.dir/testcmplx.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/grizzlysmit/Projects/C++/complexfmt/testcmplx.cpp > CMakeFiles/testcmplx.dir/testcmplx.cpp.i

CMakeFiles/testcmplx.dir/testcmplx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testcmplx.dir/testcmplx.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/grizzlysmit/Projects/C++/complexfmt/testcmplx.cpp -o CMakeFiles/testcmplx.dir/testcmplx.cpp.s

# Object files for target testcmplx
testcmplx_OBJECTS = \
"CMakeFiles/testcmplx.dir/testcmplx.cpp.o"

# External object files for target testcmplx
testcmplx_EXTERNAL_OBJECTS =

testcmplx: CMakeFiles/testcmplx.dir/testcmplx.cpp.o
testcmplx: CMakeFiles/testcmplx.dir/build.make
testcmplx: CMakeFiles/testcmplx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grizzlysmit/Projects/C++/complexfmt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testcmplx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testcmplx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testcmplx.dir/build: testcmplx
.PHONY : CMakeFiles/testcmplx.dir/build

CMakeFiles/testcmplx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testcmplx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testcmplx.dir/clean

CMakeFiles/testcmplx.dir/depend:
	cd /home/grizzlysmit/Projects/C++/complexfmt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grizzlysmit/Projects/C++/complexfmt /home/grizzlysmit/Projects/C++/complexfmt /home/grizzlysmit/Projects/C++/complexfmt/build /home/grizzlysmit/Projects/C++/complexfmt/build /home/grizzlysmit/Projects/C++/complexfmt/build/CMakeFiles/testcmplx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testcmplx.dir/depend
