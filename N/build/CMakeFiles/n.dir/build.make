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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/N

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/N/build

# Include any dependencies generated for this target.
include CMakeFiles/n.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/n.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/n.dir/flags.make

CMakeFiles/n.dir/main.c.o: CMakeFiles/n.dir/flags.make
CMakeFiles/n.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/N/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/n.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/n.dir/main.c.o   -c /home/evil/Studia/Przedmioty/WdP/N/main.c

CMakeFiles/n.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/n.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/N/main.c > CMakeFiles/n.dir/main.c.i

CMakeFiles/n.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/n.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/N/main.c -o CMakeFiles/n.dir/main.c.s

CMakeFiles/n.dir/main.c.o.requires:
.PHONY : CMakeFiles/n.dir/main.c.o.requires

CMakeFiles/n.dir/main.c.o.provides: CMakeFiles/n.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/n.dir/build.make CMakeFiles/n.dir/main.c.o.provides.build
.PHONY : CMakeFiles/n.dir/main.c.o.provides

CMakeFiles/n.dir/main.c.o.provides.build: CMakeFiles/n.dir/main.c.o

# Object files for target n
n_OBJECTS = \
"CMakeFiles/n.dir/main.c.o"

# External object files for target n
n_EXTERNAL_OBJECTS =

n : CMakeFiles/n.dir/main.c.o
n : CMakeFiles/n.dir/build.make
n : CMakeFiles/n.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable n"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/n.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/n.dir/build: n
.PHONY : CMakeFiles/n.dir/build

CMakeFiles/n.dir/requires: CMakeFiles/n.dir/main.c.o.requires
.PHONY : CMakeFiles/n.dir/requires

CMakeFiles/n.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/n.dir/cmake_clean.cmake
.PHONY : CMakeFiles/n.dir/clean

CMakeFiles/n.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/N/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/N /home/evil/Studia/Przedmioty/WdP/N /home/evil/Studia/Przedmioty/WdP/N/build /home/evil/Studia/Przedmioty/WdP/N/build /home/evil/Studia/Przedmioty/WdP/N/build/CMakeFiles/n.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/n.dir/depend

