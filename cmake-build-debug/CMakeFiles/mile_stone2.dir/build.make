# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eliadsellem/CLionProjects/mile_stone2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eliadsellem/CLionProjects/mile_stone2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mile_stone2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mile_stone2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mile_stone2.dir/flags.make

CMakeFiles/mile_stone2.dir/main.cpp.o: CMakeFiles/mile_stone2.dir/flags.make
CMakeFiles/mile_stone2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/eliadsellem/CLionProjects/mile_stone2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mile_stone2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mile_stone2.dir/main.cpp.o -c /home/eliadsellem/CLionProjects/mile_stone2/main.cpp

CMakeFiles/mile_stone2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mile_stone2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/eliadsellem/CLionProjects/mile_stone2/main.cpp > CMakeFiles/mile_stone2.dir/main.cpp.i

CMakeFiles/mile_stone2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mile_stone2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/eliadsellem/CLionProjects/mile_stone2/main.cpp -o CMakeFiles/mile_stone2.dir/main.cpp.s

# Object files for target mile_stone2
mile_stone2_OBJECTS = \
"CMakeFiles/mile_stone2.dir/main.cpp.o"

# External object files for target mile_stone2
mile_stone2_EXTERNAL_OBJECTS =

mile_stone2: CMakeFiles/mile_stone2.dir/main.cpp.o
mile_stone2: CMakeFiles/mile_stone2.dir/build.make
mile_stone2: CMakeFiles/mile_stone2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/eliadsellem/CLionProjects/mile_stone2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mile_stone2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mile_stone2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mile_stone2.dir/build: mile_stone2

.PHONY : CMakeFiles/mile_stone2.dir/build

CMakeFiles/mile_stone2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mile_stone2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mile_stone2.dir/clean

CMakeFiles/mile_stone2.dir/depend:
	cd /home/eliadsellem/CLionProjects/mile_stone2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eliadsellem/CLionProjects/mile_stone2 /home/eliadsellem/CLionProjects/mile_stone2 /home/eliadsellem/CLionProjects/mile_stone2/cmake-build-debug /home/eliadsellem/CLionProjects/mile_stone2/cmake-build-debug /home/eliadsellem/CLionProjects/mile_stone2/cmake-build-debug/CMakeFiles/mile_stone2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mile_stone2.dir/depend

