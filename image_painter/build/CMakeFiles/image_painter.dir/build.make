# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/alexey/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/alexey/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexey/projects/Graph/image_painter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexey/projects/Graph/image_painter/build

# Include any dependencies generated for this target.
include CMakeFiles/image_painter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image_painter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image_painter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_painter.dir/flags.make

CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o: CMakeFiles/image_painter.dir/flags.make
CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o: image_painter_autogen/mocs_compilation.cpp
CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o: CMakeFiles/image_painter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alexey/projects/Graph/image_painter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o -MF CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o -c /home/alexey/projects/Graph/image_painter/build/image_painter_autogen/mocs_compilation.cpp

CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/projects/Graph/image_painter/build/image_painter_autogen/mocs_compilation.cpp > CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.i

CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/projects/Graph/image_painter/build/image_painter_autogen/mocs_compilation.cpp -o CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.s

CMakeFiles/image_painter.dir/image_painter.cc.o: CMakeFiles/image_painter.dir/flags.make
CMakeFiles/image_painter.dir/image_painter.cc.o: /home/alexey/projects/Graph/image_painter/image_painter.cc
CMakeFiles/image_painter.dir/image_painter.cc.o: CMakeFiles/image_painter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alexey/projects/Graph/image_painter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image_painter.dir/image_painter.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_painter.dir/image_painter.cc.o -MF CMakeFiles/image_painter.dir/image_painter.cc.o.d -o CMakeFiles/image_painter.dir/image_painter.cc.o -c /home/alexey/projects/Graph/image_painter/image_painter.cc

CMakeFiles/image_painter.dir/image_painter.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_painter.dir/image_painter.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/projects/Graph/image_painter/image_painter.cc > CMakeFiles/image_painter.dir/image_painter.cc.i

CMakeFiles/image_painter.dir/image_painter.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_painter.dir/image_painter.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/projects/Graph/image_painter/image_painter.cc -o CMakeFiles/image_painter.dir/image_painter.cc.s

# Object files for target image_painter
image_painter_OBJECTS = \
"CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/image_painter.dir/image_painter.cc.o"

# External object files for target image_painter
image_painter_EXTERNAL_OBJECTS =

libimage_painter.a: CMakeFiles/image_painter.dir/image_painter_autogen/mocs_compilation.cpp.o
libimage_painter.a: CMakeFiles/image_painter.dir/image_painter.cc.o
libimage_painter.a: CMakeFiles/image_painter.dir/build.make
libimage_painter.a: CMakeFiles/image_painter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/alexey/projects/Graph/image_painter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libimage_painter.a"
	$(CMAKE_COMMAND) -P CMakeFiles/image_painter.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image_painter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_painter.dir/build: libimage_painter.a
.PHONY : CMakeFiles/image_painter.dir/build

CMakeFiles/image_painter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image_painter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image_painter.dir/clean

CMakeFiles/image_painter.dir/depend:
	cd /home/alexey/projects/Graph/image_painter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/projects/Graph/image_painter /home/alexey/projects/Graph/image_painter /home/alexey/projects/Graph/image_painter/build /home/alexey/projects/Graph/image_painter/build /home/alexey/projects/Graph/image_painter/build/CMakeFiles/image_painter.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/image_painter.dir/depend

