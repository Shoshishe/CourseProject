# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/shosh/clion-2024.1.1/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/shosh/clion-2024.1.1/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/shosh/CourseProject/Course project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/shosh/CourseProject/Course project/cmake-build-debug"

# Utility rule file for Course_project_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/Course_project_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Course_project_autogen_timestamp_deps.dir/progress.make

CMakeFiles/Course_project_autogen_timestamp_deps: /usr/lib/libQt5Core.so.5.15.13
CMakeFiles/Course_project_autogen_timestamp_deps: /usr/lib/libQt5Gui.so.5.15.13
CMakeFiles/Course_project_autogen_timestamp_deps: /usr/bin/moc
CMakeFiles/Course_project_autogen_timestamp_deps: /usr/bin/uic
CMakeFiles/Course_project_autogen_timestamp_deps: /usr/lib/libQt5Multimedia.so.5.15.13
CMakeFiles/Course_project_autogen_timestamp_deps: /usr/lib/libQt5Network.so.5.15.13
CMakeFiles/Course_project_autogen_timestamp_deps: /usr/lib/libQt5Widgets.so.5.15.13

Course_project_autogen_timestamp_deps: CMakeFiles/Course_project_autogen_timestamp_deps
Course_project_autogen_timestamp_deps: CMakeFiles/Course_project_autogen_timestamp_deps.dir/build.make
.PHONY : Course_project_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/Course_project_autogen_timestamp_deps.dir/build: Course_project_autogen_timestamp_deps
.PHONY : CMakeFiles/Course_project_autogen_timestamp_deps.dir/build

CMakeFiles/Course_project_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Course_project_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Course_project_autogen_timestamp_deps.dir/clean

CMakeFiles/Course_project_autogen_timestamp_deps.dir/depend:
	cd "/home/shosh/CourseProject/Course project/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shosh/CourseProject/Course project" "/home/shosh/CourseProject/Course project" "/home/shosh/CourseProject/Course project/cmake-build-debug" "/home/shosh/CourseProject/Course project/cmake-build-debug" "/home/shosh/CourseProject/Course project/cmake-build-debug/CMakeFiles/Course_project_autogen_timestamp_deps.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Course_project_autogen_timestamp_deps.dir/depend
