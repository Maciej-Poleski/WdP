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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/B/build_release

# Include any dependencies generated for this target.
include CMakeFiles/b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/b.dir/flags.make

CMakeFiles/b.dir/main.c.o: CMakeFiles/b.dir/flags.make
CMakeFiles/b.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/B/build_release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/b.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/b.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/B/main.c

CMakeFiles/b.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/b.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/B/main.c > CMakeFiles/b.dir/main.c.i

CMakeFiles/b.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/b.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/B/main.c -o CMakeFiles/b.dir/main.c.s

CMakeFiles/b.dir/main.c.o.requires:
.PHONY : CMakeFiles/b.dir/main.c.o.requires

CMakeFiles/b.dir/main.c.o.provides: CMakeFiles/b.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/b.dir/build.make CMakeFiles/b.dir/main.c.o.provides.build
.PHONY : CMakeFiles/b.dir/main.c.o.provides

CMakeFiles/b.dir/main.c.o.provides.build: CMakeFiles/b.dir/main.c.o

# Object files for target b
b_OBJECTS = \
"CMakeFiles/b.dir/main.c.o"

# External object files for target b
b_EXTERNAL_OBJECTS =

b : CMakeFiles/b.dir/main.c.o
b : CMakeFiles/b.dir/build.make
b : CMakeFiles/b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable b"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/b.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/b.dir/build: b
.PHONY : CMakeFiles/b.dir/build

CMakeFiles/b.dir/requires: CMakeFiles/b.dir/main.c.o.requires
.PHONY : CMakeFiles/b.dir/requires

CMakeFiles/b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/b.dir/cmake_clean.cmake
.PHONY : CMakeFiles/b.dir/clean

CMakeFiles/b.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/B/build_release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/B /home/evil/Studia/Przedmioty/WdP/B /home/evil/Studia/Przedmioty/WdP/B/build_release /home/evil/Studia/Przedmioty/WdP/B/build_release /home/evil/Studia/Przedmioty/WdP/B/build_release/CMakeFiles/b.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/b.dir/depend
