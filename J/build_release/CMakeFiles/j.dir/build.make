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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/J

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/J/build_release

# Include any dependencies generated for this target.
include CMakeFiles/j.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/j.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/j.dir/flags.make

CMakeFiles/j.dir/main.c.o: CMakeFiles/j.dir/flags.make
CMakeFiles/j.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/J/build_release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/j.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/j.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/J/main.c

CMakeFiles/j.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/j.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/J/main.c > CMakeFiles/j.dir/main.c.i

CMakeFiles/j.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/j.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/J/main.c -o CMakeFiles/j.dir/main.c.s

CMakeFiles/j.dir/main.c.o.requires:
.PHONY : CMakeFiles/j.dir/main.c.o.requires

CMakeFiles/j.dir/main.c.o.provides: CMakeFiles/j.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/j.dir/build.make CMakeFiles/j.dir/main.c.o.provides.build
.PHONY : CMakeFiles/j.dir/main.c.o.provides

CMakeFiles/j.dir/main.c.o.provides.build: CMakeFiles/j.dir/main.c.o

# Object files for target j
j_OBJECTS = \
"CMakeFiles/j.dir/main.c.o"

# External object files for target j
j_EXTERNAL_OBJECTS =

j : CMakeFiles/j.dir/main.c.o
j : CMakeFiles/j.dir/build.make
j : CMakeFiles/j.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable j"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/j.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/j.dir/build: j
.PHONY : CMakeFiles/j.dir/build

CMakeFiles/j.dir/requires: CMakeFiles/j.dir/main.c.o.requires
.PHONY : CMakeFiles/j.dir/requires

CMakeFiles/j.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/j.dir/cmake_clean.cmake
.PHONY : CMakeFiles/j.dir/clean

CMakeFiles/j.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/J/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/J /home/evil/Studia/Przedmioty/WdP/J /home/evil/Studia/Przedmioty/WdP/J/build_release /home/evil/Studia/Przedmioty/WdP/J/build_release /home/evil/Studia/Przedmioty/WdP/J/build_release/CMakeFiles/j.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/j.dir/depend
