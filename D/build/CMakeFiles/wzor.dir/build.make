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
CMAKE_SOURCE_DIR = /home/evil/Studia/Przedmioty/WdP/D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evil/Studia/Przedmioty/WdP/D/build

# Include any dependencies generated for this target.
include CMakeFiles/wzor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wzor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wzor.dir/flags.make

CMakeFiles/wzor.dir/main.cxx.o: CMakeFiles/wzor.dir/flags.make
CMakeFiles/wzor.dir/main.cxx.o: ../main.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/evil/Studia/Przedmioty/WdP/D/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/wzor.dir/main.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/wzor.dir/main.cxx.o -c /home/evil/Studia/Przedmioty/WdP/D/main.cxx

CMakeFiles/wzor.dir/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wzor.dir/main.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/evil/Studia/Przedmioty/WdP/D/main.cxx > CMakeFiles/wzor.dir/main.cxx.i

CMakeFiles/wzor.dir/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wzor.dir/main.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/evil/Studia/Przedmioty/WdP/D/main.cxx -o CMakeFiles/wzor.dir/main.cxx.s

CMakeFiles/wzor.dir/main.cxx.o.requires:
.PHONY : CMakeFiles/wzor.dir/main.cxx.o.requires

CMakeFiles/wzor.dir/main.cxx.o.provides: CMakeFiles/wzor.dir/main.cxx.o.requires
	$(MAKE) -f CMakeFiles/wzor.dir/build.make CMakeFiles/wzor.dir/main.cxx.o.provides.build
.PHONY : CMakeFiles/wzor.dir/main.cxx.o.provides

CMakeFiles/wzor.dir/main.cxx.o.provides.build: CMakeFiles/wzor.dir/main.cxx.o

# Object files for target wzor
wzor_OBJECTS = \
"CMakeFiles/wzor.dir/main.cxx.o"

# External object files for target wzor
wzor_EXTERNAL_OBJECTS =

wzor: CMakeFiles/wzor.dir/main.cxx.o
wzor: CMakeFiles/wzor.dir/build.make
wzor: CMakeFiles/wzor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable wzor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wzor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wzor.dir/build: wzor
.PHONY : CMakeFiles/wzor.dir/build

CMakeFiles/wzor.dir/requires: CMakeFiles/wzor.dir/main.cxx.o.requires
.PHONY : CMakeFiles/wzor.dir/requires

CMakeFiles/wzor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wzor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wzor.dir/clean

CMakeFiles/wzor.dir/depend:
	cd /home/evil/Studia/Przedmioty/WdP/D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evil/Studia/Przedmioty/WdP/D /home/evil/Studia/Przedmioty/WdP/D /home/evil/Studia/Przedmioty/WdP/D/build /home/evil/Studia/Przedmioty/WdP/D/build /home/evil/Studia/Przedmioty/WdP/D/build/CMakeFiles/wzor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wzor.dir/depend

