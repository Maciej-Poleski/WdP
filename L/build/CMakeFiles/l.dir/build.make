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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/L

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/L/build

# Include any dependencies generated for this target.
include CMakeFiles/l.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/l.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/l.dir/flags.make

CMakeFiles/l.dir/main.c.o: CMakeFiles/l.dir/flags.make
CMakeFiles/l.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/L/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/l.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/l.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/L/main.c

CMakeFiles/l.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/l.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/L/main.c > CMakeFiles/l.dir/main.c.i

CMakeFiles/l.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/l.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/L/main.c -o CMakeFiles/l.dir/main.c.s

CMakeFiles/l.dir/main.c.o.requires:
.PHONY : CMakeFiles/l.dir/main.c.o.requires

CMakeFiles/l.dir/main.c.o.provides: CMakeFiles/l.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/l.dir/build.make CMakeFiles/l.dir/main.c.o.provides.build
.PHONY : CMakeFiles/l.dir/main.c.o.provides

CMakeFiles/l.dir/main.c.o.provides.build: CMakeFiles/l.dir/main.c.o

# Object files for target l
l_OBJECTS = \
"CMakeFiles/l.dir/main.c.o"

# External object files for target l
l_EXTERNAL_OBJECTS =

l : CMakeFiles/l.dir/main.c.o
l : CMakeFiles/l.dir/build.make
l : CMakeFiles/l.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable l"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/l.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/l.dir/build: l
.PHONY : CMakeFiles/l.dir/build

CMakeFiles/l.dir/requires: CMakeFiles/l.dir/main.c.o.requires
.PHONY : CMakeFiles/l.dir/requires

CMakeFiles/l.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/l.dir/cmake_clean.cmake
.PHONY : CMakeFiles/l.dir/clean

CMakeFiles/l.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/L/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/L /home/evil/Studia/Przedmioty/WdP/L /home/evil/Studia/Przedmioty/WdP/L/build /home/evil/Studia/Przedmioty/WdP/L/build /home/evil/Studia/Przedmioty/WdP/L/build/CMakeFiles/l.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/l.dir/depend

