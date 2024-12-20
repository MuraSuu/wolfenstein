# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/murasuu/Programming/wolfenstein

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/murasuu/Programming/wolfenstein/build

# Include any dependencies generated for this target.
include CMakeFiles/raycaster.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/raycaster.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raycaster.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raycaster.dir/flags.make

CMakeFiles/raycaster.dir/codegen:
.PHONY : CMakeFiles/raycaster.dir/codegen

CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o: CMakeFiles/raycaster.dir/flags.make
CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o: /home/murasuu/Programming/wolfenstein/src/SDL_Manager.cc
CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o: CMakeFiles/raycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/murasuu/Programming/wolfenstein/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o -MF CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o.d -o CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o -c /home/murasuu/Programming/wolfenstein/src/SDL_Manager.cc

CMakeFiles/raycaster.dir/src/SDL_Manager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/raycaster.dir/src/SDL_Manager.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/murasuu/Programming/wolfenstein/src/SDL_Manager.cc > CMakeFiles/raycaster.dir/src/SDL_Manager.cc.i

CMakeFiles/raycaster.dir/src/SDL_Manager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/raycaster.dir/src/SDL_Manager.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/murasuu/Programming/wolfenstein/src/SDL_Manager.cc -o CMakeFiles/raycaster.dir/src/SDL_Manager.cc.s

CMakeFiles/raycaster.dir/src/graphics.cc.o: CMakeFiles/raycaster.dir/flags.make
CMakeFiles/raycaster.dir/src/graphics.cc.o: /home/murasuu/Programming/wolfenstein/src/graphics.cc
CMakeFiles/raycaster.dir/src/graphics.cc.o: CMakeFiles/raycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/murasuu/Programming/wolfenstein/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/raycaster.dir/src/graphics.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raycaster.dir/src/graphics.cc.o -MF CMakeFiles/raycaster.dir/src/graphics.cc.o.d -o CMakeFiles/raycaster.dir/src/graphics.cc.o -c /home/murasuu/Programming/wolfenstein/src/graphics.cc

CMakeFiles/raycaster.dir/src/graphics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/raycaster.dir/src/graphics.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/murasuu/Programming/wolfenstein/src/graphics.cc > CMakeFiles/raycaster.dir/src/graphics.cc.i

CMakeFiles/raycaster.dir/src/graphics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/raycaster.dir/src/graphics.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/murasuu/Programming/wolfenstein/src/graphics.cc -o CMakeFiles/raycaster.dir/src/graphics.cc.s

CMakeFiles/raycaster.dir/src/main.cc.o: CMakeFiles/raycaster.dir/flags.make
CMakeFiles/raycaster.dir/src/main.cc.o: /home/murasuu/Programming/wolfenstein/src/main.cc
CMakeFiles/raycaster.dir/src/main.cc.o: CMakeFiles/raycaster.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/murasuu/Programming/wolfenstein/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/raycaster.dir/src/main.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/raycaster.dir/src/main.cc.o -MF CMakeFiles/raycaster.dir/src/main.cc.o.d -o CMakeFiles/raycaster.dir/src/main.cc.o -c /home/murasuu/Programming/wolfenstein/src/main.cc

CMakeFiles/raycaster.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/raycaster.dir/src/main.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/murasuu/Programming/wolfenstein/src/main.cc > CMakeFiles/raycaster.dir/src/main.cc.i

CMakeFiles/raycaster.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/raycaster.dir/src/main.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/murasuu/Programming/wolfenstein/src/main.cc -o CMakeFiles/raycaster.dir/src/main.cc.s

# Object files for target raycaster
raycaster_OBJECTS = \
"CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o" \
"CMakeFiles/raycaster.dir/src/graphics.cc.o" \
"CMakeFiles/raycaster.dir/src/main.cc.o"

# External object files for target raycaster
raycaster_EXTERNAL_OBJECTS =

raycaster: CMakeFiles/raycaster.dir/src/SDL_Manager.cc.o
raycaster: CMakeFiles/raycaster.dir/src/graphics.cc.o
raycaster: CMakeFiles/raycaster.dir/src/main.cc.o
raycaster: CMakeFiles/raycaster.dir/build.make
raycaster: /usr/local/lib/libSDL2.so
raycaster: CMakeFiles/raycaster.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/murasuu/Programming/wolfenstein/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable raycaster"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raycaster.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raycaster.dir/build: raycaster
.PHONY : CMakeFiles/raycaster.dir/build

CMakeFiles/raycaster.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raycaster.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raycaster.dir/clean

CMakeFiles/raycaster.dir/depend:
	cd /home/murasuu/Programming/wolfenstein/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/murasuu/Programming/wolfenstein /home/murasuu/Programming/wolfenstein /home/murasuu/Programming/wolfenstein/build /home/murasuu/Programming/wolfenstein/build /home/murasuu/Programming/wolfenstein/build/CMakeFiles/raycaster.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/raycaster.dir/depend

