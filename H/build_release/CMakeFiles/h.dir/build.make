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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/H

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/H/build_release

# Include any dependencies generated for this target.
include CMakeFiles/h.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/h.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/h.dir/flags.make

CMakeFiles/h.dir/main.c.o: CMakeFiles/h.dir/flags.make
CMakeFiles/h.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/H/build_release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/h.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/h.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/H/main.c

CMakeFiles/h.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/h.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/H/main.c > CMakeFiles/h.dir/main.c.i

CMakeFiles/h.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/h.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/H/main.c -o CMakeFiles/h.dir/main.c.s

CMakeFiles/h.dir/main.c.o.requires:
.PHONY : CMakeFiles/h.dir/main.c.o.requires

CMakeFiles/h.dir/main.c.o.provides: CMakeFiles/h.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/h.dir/build.make CMakeFiles/h.dir/main.c.o.provides.build
.PHONY : CMakeFiles/h.dir/main.c.o.provides

CMakeFiles/h.dir/main.c.o.provides.build: CMakeFiles/h.dir/main.c.o

# Object files for target h
h_OBJECTS = \
"CMakeFiles/h.dir/main.c.o"

# External object files for target h
h_EXTERNAL_OBJECTS =

h : CMakeFiles/h.dir/main.c.o
h : CMakeFiles/h.dir/build.make
h : CMakeFiles/h.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable h"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/h.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/h.dir/build: h
.PHONY : CMakeFiles/h.dir/build

CMakeFiles/h.dir/requires: CMakeFiles/h.dir/main.c.o.requires
.PHONY : CMakeFiles/h.dir/requires

CMakeFiles/h.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/h.dir/cmake_clean.cmake
.PHONY : CMakeFiles/h.dir/clean

CMakeFiles/h.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/H/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/H /home/evil/Studia/Przedmioty/WdP/H /home/evil/Studia/Przedmioty/WdP/H/build_release /home/evil/Studia/Przedmioty/WdP/H/build_release /home/evil/Studia/Przedmioty/WdP/H/build_release/CMakeFiles/h.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/h.dir/depend

