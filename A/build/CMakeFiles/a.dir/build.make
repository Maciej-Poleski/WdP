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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/A

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/A/build

# Include any dependencies generated for this target.
include CMakeFiles/a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.dir/flags.make

CMakeFiles/a.dir/main.c.o: CMakeFiles/a.dir/flags.make
CMakeFiles/a.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/A/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/a.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/a.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/A/main.c

CMakeFiles/a.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/a.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/A/main.c > CMakeFiles/a.dir/main.c.i

CMakeFiles/a.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/a.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/A/main.c -o CMakeFiles/a.dir/main.c.s

CMakeFiles/a.dir/main.c.o.requires:
.PHONY : CMakeFiles/a.dir/main.c.o.requires

CMakeFiles/a.dir/main.c.o.provides: CMakeFiles/a.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/a.dir/build.make CMakeFiles/a.dir/main.c.o.provides.build
.PHONY : CMakeFiles/a.dir/main.c.o.provides

CMakeFiles/a.dir/main.c.o.provides.build: CMakeFiles/a.dir/main.c.o

# Object files for target a
a_OBJECTS = \
"CMakeFiles/a.dir/main.c.o"

# External object files for target a
a_EXTERNAL_OBJECTS =

a : CMakeFiles/a.dir/main.c.o
a : CMakeFiles/a.dir/build.make
a : CMakeFiles/a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.dir/build: a
.PHONY : CMakeFiles/a.dir/build

CMakeFiles/a.dir/requires: CMakeFiles/a.dir/main.c.o.requires
.PHONY : CMakeFiles/a.dir/requires

CMakeFiles/a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.dir/clean

CMakeFiles/a.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/A/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/A /home/evil/Studia/Przedmioty/WdP/A /home/evil/Studia/Przedmioty/WdP/A/build /home/evil/Studia/Przedmioty/WdP/A/build /home/evil/Studia/Przedmioty/WdP/A/build/CMakeFiles/a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.dir/depend

