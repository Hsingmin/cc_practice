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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alfred/workspace/cc_practice/mk_tools/tool_proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alfred/workspace/cc_practice/mk_tools/tool_proj/build

# Include any dependencies generated for this target.
include CMakeFiles/tool_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tool_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tool_main.dir/flags.make

CMakeFiles/tool_main.dir/mytool2.c.o: CMakeFiles/tool_main.dir/flags.make
CMakeFiles/tool_main.dir/mytool2.c.o: ../mytool2.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alfred/workspace/cc_practice/mk_tools/tool_proj/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/tool_main.dir/mytool2.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tool_main.dir/mytool2.c.o   -c /home/alfred/workspace/cc_practice/mk_tools/tool_proj/mytool2.c

CMakeFiles/tool_main.dir/mytool2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tool_main.dir/mytool2.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alfred/workspace/cc_practice/mk_tools/tool_proj/mytool2.c > CMakeFiles/tool_main.dir/mytool2.c.i

CMakeFiles/tool_main.dir/mytool2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tool_main.dir/mytool2.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alfred/workspace/cc_practice/mk_tools/tool_proj/mytool2.c -o CMakeFiles/tool_main.dir/mytool2.c.s

CMakeFiles/tool_main.dir/mytool2.c.o.requires:
.PHONY : CMakeFiles/tool_main.dir/mytool2.c.o.requires

CMakeFiles/tool_main.dir/mytool2.c.o.provides: CMakeFiles/tool_main.dir/mytool2.c.o.requires
	$(MAKE) -f CMakeFiles/tool_main.dir/build.make CMakeFiles/tool_main.dir/mytool2.c.o.provides.build
.PHONY : CMakeFiles/tool_main.dir/mytool2.c.o.provides

CMakeFiles/tool_main.dir/mytool2.c.o.provides.build: CMakeFiles/tool_main.dir/mytool2.c.o

CMakeFiles/tool_main.dir/main.c.o: CMakeFiles/tool_main.dir/flags.make
CMakeFiles/tool_main.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alfred/workspace/cc_practice/mk_tools/tool_proj/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/tool_main.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tool_main.dir/main.c.o   -c /home/alfred/workspace/cc_practice/mk_tools/tool_proj/main.c

CMakeFiles/tool_main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tool_main.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alfred/workspace/cc_practice/mk_tools/tool_proj/main.c > CMakeFiles/tool_main.dir/main.c.i

CMakeFiles/tool_main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tool_main.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alfred/workspace/cc_practice/mk_tools/tool_proj/main.c -o CMakeFiles/tool_main.dir/main.c.s

CMakeFiles/tool_main.dir/main.c.o.requires:
.PHONY : CMakeFiles/tool_main.dir/main.c.o.requires

CMakeFiles/tool_main.dir/main.c.o.provides: CMakeFiles/tool_main.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/tool_main.dir/build.make CMakeFiles/tool_main.dir/main.c.o.provides.build
.PHONY : CMakeFiles/tool_main.dir/main.c.o.provides

CMakeFiles/tool_main.dir/main.c.o.provides.build: CMakeFiles/tool_main.dir/main.c.o

CMakeFiles/tool_main.dir/mytool1.c.o: CMakeFiles/tool_main.dir/flags.make
CMakeFiles/tool_main.dir/mytool1.c.o: ../mytool1.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/alfred/workspace/cc_practice/mk_tools/tool_proj/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/tool_main.dir/mytool1.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/tool_main.dir/mytool1.c.o   -c /home/alfred/workspace/cc_practice/mk_tools/tool_proj/mytool1.c

CMakeFiles/tool_main.dir/mytool1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tool_main.dir/mytool1.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/alfred/workspace/cc_practice/mk_tools/tool_proj/mytool1.c > CMakeFiles/tool_main.dir/mytool1.c.i

CMakeFiles/tool_main.dir/mytool1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tool_main.dir/mytool1.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/alfred/workspace/cc_practice/mk_tools/tool_proj/mytool1.c -o CMakeFiles/tool_main.dir/mytool1.c.s

CMakeFiles/tool_main.dir/mytool1.c.o.requires:
.PHONY : CMakeFiles/tool_main.dir/mytool1.c.o.requires

CMakeFiles/tool_main.dir/mytool1.c.o.provides: CMakeFiles/tool_main.dir/mytool1.c.o.requires
	$(MAKE) -f CMakeFiles/tool_main.dir/build.make CMakeFiles/tool_main.dir/mytool1.c.o.provides.build
.PHONY : CMakeFiles/tool_main.dir/mytool1.c.o.provides

CMakeFiles/tool_main.dir/mytool1.c.o.provides.build: CMakeFiles/tool_main.dir/mytool1.c.o

# Object files for target tool_main
tool_main_OBJECTS = \
"CMakeFiles/tool_main.dir/mytool2.c.o" \
"CMakeFiles/tool_main.dir/main.c.o" \
"CMakeFiles/tool_main.dir/mytool1.c.o"

# External object files for target tool_main
tool_main_EXTERNAL_OBJECTS =

tool_main: CMakeFiles/tool_main.dir/mytool2.c.o
tool_main: CMakeFiles/tool_main.dir/main.c.o
tool_main: CMakeFiles/tool_main.dir/mytool1.c.o
tool_main: CMakeFiles/tool_main.dir/build.make
tool_main: CMakeFiles/tool_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable tool_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tool_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tool_main.dir/build: tool_main
.PHONY : CMakeFiles/tool_main.dir/build

CMakeFiles/tool_main.dir/requires: CMakeFiles/tool_main.dir/mytool2.c.o.requires
CMakeFiles/tool_main.dir/requires: CMakeFiles/tool_main.dir/main.c.o.requires
CMakeFiles/tool_main.dir/requires: CMakeFiles/tool_main.dir/mytool1.c.o.requires
.PHONY : CMakeFiles/tool_main.dir/requires

CMakeFiles/tool_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tool_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tool_main.dir/clean

CMakeFiles/tool_main.dir/depend:
	cd /home/alfred/workspace/cc_practice/mk_tools/tool_proj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alfred/workspace/cc_practice/mk_tools/tool_proj /home/alfred/workspace/cc_practice/mk_tools/tool_proj /home/alfred/workspace/cc_practice/mk_tools/tool_proj/build /home/alfred/workspace/cc_practice/mk_tools/tool_proj/build /home/alfred/workspace/cc_practice/mk_tools/tool_proj/build/CMakeFiles/tool_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tool_main.dir/depend
