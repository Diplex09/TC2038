# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible"

# Include any dependencies generated for this target.
include CMakeFiles/delaunay.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/delaunay.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/delaunay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/delaunay.dir/flags.make

CMakeFiles/delaunay.dir/delaunay.cpp.o: CMakeFiles/delaunay.dir/flags.make
CMakeFiles/delaunay.dir/delaunay.cpp.o: delaunay.cpp
CMakeFiles/delaunay.dir/delaunay.cpp.o: CMakeFiles/delaunay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/delaunay.dir/delaunay.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/delaunay.dir/delaunay.cpp.o -MF CMakeFiles/delaunay.dir/delaunay.cpp.o.d -o CMakeFiles/delaunay.dir/delaunay.cpp.o -c "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible/delaunay.cpp"

CMakeFiles/delaunay.dir/delaunay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/delaunay.dir/delaunay.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible/delaunay.cpp" > CMakeFiles/delaunay.dir/delaunay.cpp.i

CMakeFiles/delaunay.dir/delaunay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/delaunay.dir/delaunay.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible/delaunay.cpp" -o CMakeFiles/delaunay.dir/delaunay.cpp.s

# Object files for target delaunay
delaunay_OBJECTS = \
"CMakeFiles/delaunay.dir/delaunay.cpp.o"

# External object files for target delaunay
delaunay_EXTERNAL_OBJECTS =

delaunay: CMakeFiles/delaunay.dir/delaunay.cpp.o
delaunay: CMakeFiles/delaunay.dir/build.make
delaunay: /Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
delaunay: /Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk/System/Library/Frameworks/GLUT.framework/GLUT.tbd
delaunay: /usr/local/lib/libgmpxx.dylib
delaunay: /usr/local/lib/libmpfr.dylib
delaunay: /usr/local/lib/libgmp.dylib
delaunay: /Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk/System/Library/Frameworks/Cocoa.framework/Cocoa.tbd
delaunay: CMakeFiles/delaunay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable delaunay"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/delaunay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/delaunay.dir/build: delaunay
.PHONY : CMakeFiles/delaunay.dir/build

CMakeFiles/delaunay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/delaunay.dir/cmake_clean.cmake
.PHONY : CMakeFiles/delaunay.dir/clean

CMakeFiles/delaunay.dir/depend:
	cd "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible" "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible" "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible" "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible" "/Users/diegovelazquez/Documents/GitHub/TC2038/Actividad imposible/CMakeFiles/delaunay.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/delaunay.dir/depend

