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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/M

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/M/build

# Include any dependencies generated for this target.
include CMakeFiles/m.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/m.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/m.dir/flags.make

CMakeFiles/m.dir/main.c.o: CMakeFiles/m.dir/flags.make
CMakeFiles/m.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/M/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/m.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/m.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/M/main.c

CMakeFiles/m.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/m.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/M/main.c > CMakeFiles/m.dir/main.c.i

CMakeFiles/m.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/m.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/M/main.c -o CMakeFiles/m.dir/main.c.s

CMakeFiles/m.dir/main.c.o.requires:
.PHONY : CMakeFiles/m.dir/main.c.o.requires

CMakeFiles/m.dir/main.c.o.provides: CMakeFiles/m.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/m.dir/build.make CMakeFiles/m.dir/main.c.o.provides.build
.PHONY : CMakeFiles/m.dir/main.c.o.provides

CMakeFiles/m.dir/main.c.o.provides.build: CMakeFiles/m.dir/main.c.o

# Object files for target m
m_OBJECTS = \
"CMakeFiles/m.dir/main.c.o"

# External object files for target m
m_EXTERNAL_OBJECTS =

m : CMakeFiles/m.dir/main.c.o
m : CMakeFiles/m.dir/build.make
m : CMakeFiles/m.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable m"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/m.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/m.dir/build: m
.PHONY : CMakeFiles/m.dir/build

CMakeFiles/m.dir/requires: CMakeFiles/m.dir/main.c.o.requires
.PHONY : CMakeFiles/m.dir/requires

CMakeFiles/m.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/m.dir/cmake_clean.cmake
.PHONY : CMakeFiles/m.dir/clean

CMakeFiles/m.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/M/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/M /home/evil/Studia/Przedmioty/WdP/M /home/evil/Studia/Przedmioty/WdP/M/build /home/evil/Studia/Przedmioty/WdP/M/build /home/evil/Studia/Przedmioty/WdP/M/build/CMakeFiles/m.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/m.dir/depend

