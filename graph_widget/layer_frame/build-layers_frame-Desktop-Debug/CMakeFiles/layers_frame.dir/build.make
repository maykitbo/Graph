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
CMAKE_SOURCE_DIR = /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/layers_frame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/layers_frame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/layers_frame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/layers_frame.dir/flags.make

CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o: CMakeFiles/layers_frame.dir/flags.make
CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o: layers_frame_autogen/mocs_compilation.cpp
CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o: CMakeFiles/layers_frame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o -MF CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o -c /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug/layers_frame_autogen/mocs_compilation.cpp

CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug/layers_frame_autogen/mocs_compilation.cpp > CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.i

CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug/layers_frame_autogen/mocs_compilation.cpp -o CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.s

CMakeFiles/layers_frame.dir/main.cpp.o: CMakeFiles/layers_frame.dir/flags.make
CMakeFiles/layers_frame.dir/main.cpp.o: /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame/main.cpp
CMakeFiles/layers_frame.dir/main.cpp.o: CMakeFiles/layers_frame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/layers_frame.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layers_frame.dir/main.cpp.o -MF CMakeFiles/layers_frame.dir/main.cpp.o.d -o CMakeFiles/layers_frame.dir/main.cpp.o -c /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame/main.cpp

CMakeFiles/layers_frame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layers_frame.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame/main.cpp > CMakeFiles/layers_frame.dir/main.cpp.i

CMakeFiles/layers_frame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layers_frame.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame/main.cpp -o CMakeFiles/layers_frame.dir/main.cpp.s

CMakeFiles/layers_frame.dir/layers_frame.cpp.o: CMakeFiles/layers_frame.dir/flags.make
CMakeFiles/layers_frame.dir/layers_frame.cpp.o: /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame/layers_frame.cpp
CMakeFiles/layers_frame.dir/layers_frame.cpp.o: CMakeFiles/layers_frame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/layers_frame.dir/layers_frame.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layers_frame.dir/layers_frame.cpp.o -MF CMakeFiles/layers_frame.dir/layers_frame.cpp.o.d -o CMakeFiles/layers_frame.dir/layers_frame.cpp.o -c /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame/layers_frame.cpp

CMakeFiles/layers_frame.dir/layers_frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layers_frame.dir/layers_frame.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame/layers_frame.cpp > CMakeFiles/layers_frame.dir/layers_frame.cpp.i

CMakeFiles/layers_frame.dir/layers_frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layers_frame.dir/layers_frame.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame/layers_frame.cpp -o CMakeFiles/layers_frame.dir/layers_frame.cpp.s

# Object files for target layers_frame
layers_frame_OBJECTS = \
"CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/layers_frame.dir/main.cpp.o" \
"CMakeFiles/layers_frame.dir/layers_frame.cpp.o"

# External object files for target layers_frame
layers_frame_EXTERNAL_OBJECTS =

layers_frame: CMakeFiles/layers_frame.dir/layers_frame_autogen/mocs_compilation.cpp.o
layers_frame: CMakeFiles/layers_frame.dir/main.cpp.o
layers_frame: CMakeFiles/layers_frame.dir/layers_frame.cpp.o
layers_frame: CMakeFiles/layers_frame.dir/build.make
layers_frame: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
layers_frame: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
layers_frame: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
layers_frame: CMakeFiles/layers_frame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable layers_frame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/layers_frame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/layers_frame.dir/build: layers_frame
.PHONY : CMakeFiles/layers_frame.dir/build

CMakeFiles/layers_frame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/layers_frame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/layers_frame.dir/clean

CMakeFiles/layers_frame.dir/depend:
	cd /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/layers_frame /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug /home/alexey/projects/algorithmic_trading/src/view/graph_widget/layer_frame/build-layers_frame-Desktop-Debug/CMakeFiles/layers_frame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/layers_frame.dir/depend
