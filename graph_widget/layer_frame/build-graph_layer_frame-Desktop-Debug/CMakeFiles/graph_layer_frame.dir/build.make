# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/graph_layer_frame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/graph_layer_frame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/graph_layer_frame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graph_layer_frame.dir/flags.make

CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o: CMakeFiles/graph_layer_frame.dir/flags.make
CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o: graph_layer_frame_autogen/mocs_compilation.cpp
CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o: CMakeFiles/graph_layer_frame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o -MF CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o -c /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug/graph_layer_frame_autogen/mocs_compilation.cpp

CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug/graph_layer_frame_autogen/mocs_compilation.cpp > CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.i

CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug/graph_layer_frame_autogen/mocs_compilation.cpp -o CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.s

CMakeFiles/graph_layer_frame.dir/main.cpp.o: CMakeFiles/graph_layer_frame.dir/flags.make
CMakeFiles/graph_layer_frame.dir/main.cpp.o: /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame/main.cpp
CMakeFiles/graph_layer_frame.dir/main.cpp.o: CMakeFiles/graph_layer_frame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graph_layer_frame.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph_layer_frame.dir/main.cpp.o -MF CMakeFiles/graph_layer_frame.dir/main.cpp.o.d -o CMakeFiles/graph_layer_frame.dir/main.cpp.o -c /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame/main.cpp

CMakeFiles/graph_layer_frame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph_layer_frame.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame/main.cpp > CMakeFiles/graph_layer_frame.dir/main.cpp.i

CMakeFiles/graph_layer_frame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph_layer_frame.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame/main.cpp -o CMakeFiles/graph_layer_frame.dir/main.cpp.s

CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o: CMakeFiles/graph_layer_frame.dir/flags.make
CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o: /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame/grpah_layer_frame.cc
CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o: CMakeFiles/graph_layer_frame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o -MF CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o.d -o CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o -c /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame/grpah_layer_frame.cc

CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame/grpah_layer_frame.cc > CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.i

CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame/grpah_layer_frame.cc -o CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.s

# Object files for target graph_layer_frame
graph_layer_frame_OBJECTS = \
"CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/graph_layer_frame.dir/main.cpp.o" \
"CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o"

# External object files for target graph_layer_frame
graph_layer_frame_EXTERNAL_OBJECTS =

graph_layer_frame: CMakeFiles/graph_layer_frame.dir/graph_layer_frame_autogen/mocs_compilation.cpp.o
graph_layer_frame: CMakeFiles/graph_layer_frame.dir/main.cpp.o
graph_layer_frame: CMakeFiles/graph_layer_frame.dir/grpah_layer_frame.cc.o
graph_layer_frame: CMakeFiles/graph_layer_frame.dir/build.make
graph_layer_frame: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
graph_layer_frame: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
graph_layer_frame: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
graph_layer_frame: CMakeFiles/graph_layer_frame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable graph_layer_frame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graph_layer_frame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graph_layer_frame.dir/build: graph_layer_frame
.PHONY : CMakeFiles/graph_layer_frame.dir/build

CMakeFiles/graph_layer_frame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graph_layer_frame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graph_layer_frame.dir/clean

CMakeFiles/graph_layer_frame.dir/depend:
	cd /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/graph_layer_frame /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-graph_layer_frame-Desktop-Debug/CMakeFiles/graph_layer_frame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graph_layer_frame.dir/depend
