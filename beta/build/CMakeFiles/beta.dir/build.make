# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/beta

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/beta/build

# Include any dependencies generated for this target.
include CMakeFiles/beta.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/beta.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/beta.dir/flags.make

CMakeFiles/beta.dir/main.c.o: CMakeFiles/beta.dir/flags.make
CMakeFiles/beta.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/beta/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/beta.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/beta.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/beta/main.c

CMakeFiles/beta.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/beta.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/beta/main.c > CMakeFiles/beta.dir/main.c.i

CMakeFiles/beta.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/beta.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/beta/main.c -o CMakeFiles/beta.dir/main.c.s

CMakeFiles/beta.dir/main.c.o.requires:
.PHONY : CMakeFiles/beta.dir/main.c.o.requires

CMakeFiles/beta.dir/main.c.o.provides: CMakeFiles/beta.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/beta.dir/build.make CMakeFiles/beta.dir/main.c.o.provides.build
.PHONY : CMakeFiles/beta.dir/main.c.o.provides

CMakeFiles/beta.dir/main.c.o.provides.build: CMakeFiles/beta.dir/main.c.o

# Object files for target beta
beta_OBJECTS = \
"CMakeFiles/beta.dir/main.c.o"

# External object files for target beta
beta_EXTERNAL_OBJECTS =

beta: CMakeFiles/beta.dir/main.c.o
beta: CMakeFiles/beta.dir/build.make
beta: CMakeFiles/beta.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable beta"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/beta.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/beta.dir/build: beta
.PHONY : CMakeFiles/beta.dir/build

CMakeFiles/beta.dir/requires: CMakeFiles/beta.dir/main.c.o.requires
.PHONY : CMakeFiles/beta.dir/requires

CMakeFiles/beta.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/beta.dir/cmake_clean.cmake
.PHONY : CMakeFiles/beta.dir/clean

CMakeFiles/beta.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/beta/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/beta /home/evil/Studia/Przedmioty/WdP/beta /home/evil/Studia/Przedmioty/WdP/beta/build /home/evil/Studia/Przedmioty/WdP/beta/build /home/evil/Studia/Przedmioty/WdP/beta/build/CMakeFiles/beta.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/beta.dir/depend

