# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/E

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/E/build

# Include any dependencies generated for this target.
include CMakeFiles/find_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/find_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/find_test.dir/flags.make

CMakeFiles/find_test.dir/find.cxx.o: CMakeFiles/find_test.dir/flags.make
CMakeFiles/find_test.dir/find.cxx.o: ../find.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/E/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/find_test.dir/find.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/find_test.dir/find.cxx.o -c /home/evil/Studia/Przedmioty/WdP/E/find.cxx

CMakeFiles/find_test.dir/find.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/find_test.dir/find.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/E/find.cxx > CMakeFiles/find_test.dir/find.cxx.i

CMakeFiles/find_test.dir/find.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/find_test.dir/find.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/E/find.cxx -o CMakeFiles/find_test.dir/find.cxx.s

CMakeFiles/find_test.dir/find.cxx.o.requires:
.PHONY : CMakeFiles/find_test.dir/find.cxx.o.requires

CMakeFiles/find_test.dir/find.cxx.o.provides: CMakeFiles/find_test.dir/find.cxx.o.requires
	$(MAKE) -f CMakeFiles/find_test.dir/build.make CMakeFiles/find_test.dir/find.cxx.o.provides.build
.PHONY : CMakeFiles/find_test.dir/find.cxx.o.provides

CMakeFiles/find_test.dir/find.cxx.o.provides.build: CMakeFiles/find_test.dir/find.cxx.o

# Object files for target find_test
find_test_OBJECTS = \
"CMakeFiles/find_test.dir/find.cxx.o"

# External object files for target find_test
find_test_EXTERNAL_OBJECTS =

find_test: CMakeFiles/find_test.dir/find.cxx.o
find_test: CMakeFiles/find_test.dir/build.make
find_test: CMakeFiles/find_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable find_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/find_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/find_test.dir/build: find_test
.PHONY : CMakeFiles/find_test.dir/build

CMakeFiles/find_test.dir/requires: CMakeFiles/find_test.dir/find.cxx.o.requires
.PHONY : CMakeFiles/find_test.dir/requires

CMakeFiles/find_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/find_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/find_test.dir/clean

CMakeFiles/find_test.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/E/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/E /home/evil/Studia/Przedmioty/WdP/E /home/evil/Studia/Przedmioty/WdP/E/build /home/evil/Studia/Przedmioty/WdP/E/build /home/evil/Studia/Przedmioty/WdP/E/build/CMakeFiles/find_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/find_test.dir/depend

