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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/T

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/T/build

# Include any dependencies generated for this target.
include CMakeFiles/t.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/t.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/t.dir/flags.make

CMakeFiles/t.dir/main.c.o: CMakeFiles/t.dir/flags.make
CMakeFiles/t.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/T/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/t.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/t.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/T/main.c

CMakeFiles/t.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/t.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/T/main.c > CMakeFiles/t.dir/main.c.i

CMakeFiles/t.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/t.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/T/main.c -o CMakeFiles/t.dir/main.c.s

CMakeFiles/t.dir/main.c.o.requires:
.PHONY : CMakeFiles/t.dir/main.c.o.requires

CMakeFiles/t.dir/main.c.o.provides: CMakeFiles/t.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/t.dir/build.make CMakeFiles/t.dir/main.c.o.provides.build
.PHONY : CMakeFiles/t.dir/main.c.o.provides

CMakeFiles/t.dir/main.c.o.provides.build: CMakeFiles/t.dir/main.c.o

# Object files for target t
t_OBJECTS = \
"CMakeFiles/t.dir/main.c.o"

# External object files for target t
t_EXTERNAL_OBJECTS =

t : CMakeFiles/t.dir/main.c.o
t : CMakeFiles/t.dir/build.make
t : CMakeFiles/t.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable t"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/t.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/t.dir/build: t
.PHONY : CMakeFiles/t.dir/build

CMakeFiles/t.dir/requires: CMakeFiles/t.dir/main.c.o.requires
.PHONY : CMakeFiles/t.dir/requires

CMakeFiles/t.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/t.dir/cmake_clean.cmake
.PHONY : CMakeFiles/t.dir/clean

CMakeFiles/t.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/T/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/T /home/evil/Studia/Przedmioty/WdP/T /home/evil/Studia/Przedmioty/WdP/T/build /home/evil/Studia/Przedmioty/WdP/T/build /home/evil/Studia/Przedmioty/WdP/T/build/CMakeFiles/t.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/t.dir/depend
