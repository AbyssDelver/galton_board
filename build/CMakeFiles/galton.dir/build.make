# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liamcavini/programming/galton_board

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liamcavini/programming/galton_board/build

# Include any dependencies generated for this target.
include CMakeFiles/galton.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/galton.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/galton.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/galton.dir/flags.make

CMakeFiles/galton.dir/main.cpp.o: CMakeFiles/galton.dir/flags.make
CMakeFiles/galton.dir/main.cpp.o: ../main.cpp
CMakeFiles/galton.dir/main.cpp.o: CMakeFiles/galton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liamcavini/programming/galton_board/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/galton.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/galton.dir/main.cpp.o -MF CMakeFiles/galton.dir/main.cpp.o.d -o CMakeFiles/galton.dir/main.cpp.o -c /Users/liamcavini/programming/galton_board/main.cpp

CMakeFiles/galton.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galton.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liamcavini/programming/galton_board/main.cpp > CMakeFiles/galton.dir/main.cpp.i

CMakeFiles/galton.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galton.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liamcavini/programming/galton_board/main.cpp -o CMakeFiles/galton.dir/main.cpp.s

CMakeFiles/galton.dir/board.cpp.o: CMakeFiles/galton.dir/flags.make
CMakeFiles/galton.dir/board.cpp.o: ../board.cpp
CMakeFiles/galton.dir/board.cpp.o: CMakeFiles/galton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liamcavini/programming/galton_board/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/galton.dir/board.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/galton.dir/board.cpp.o -MF CMakeFiles/galton.dir/board.cpp.o.d -o CMakeFiles/galton.dir/board.cpp.o -c /Users/liamcavini/programming/galton_board/board.cpp

CMakeFiles/galton.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galton.dir/board.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liamcavini/programming/galton_board/board.cpp > CMakeFiles/galton.dir/board.cpp.i

CMakeFiles/galton.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galton.dir/board.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liamcavini/programming/galton_board/board.cpp -o CMakeFiles/galton.dir/board.cpp.s

CMakeFiles/galton.dir/iopegs.cpp.o: CMakeFiles/galton.dir/flags.make
CMakeFiles/galton.dir/iopegs.cpp.o: ../iopegs.cpp
CMakeFiles/galton.dir/iopegs.cpp.o: CMakeFiles/galton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liamcavini/programming/galton_board/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/galton.dir/iopegs.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/galton.dir/iopegs.cpp.o -MF CMakeFiles/galton.dir/iopegs.cpp.o.d -o CMakeFiles/galton.dir/iopegs.cpp.o -c /Users/liamcavini/programming/galton_board/iopegs.cpp

CMakeFiles/galton.dir/iopegs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/galton.dir/iopegs.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liamcavini/programming/galton_board/iopegs.cpp > CMakeFiles/galton.dir/iopegs.cpp.i

CMakeFiles/galton.dir/iopegs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/galton.dir/iopegs.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liamcavini/programming/galton_board/iopegs.cpp -o CMakeFiles/galton.dir/iopegs.cpp.s

# Object files for target galton
galton_OBJECTS = \
"CMakeFiles/galton.dir/main.cpp.o" \
"CMakeFiles/galton.dir/board.cpp.o" \
"CMakeFiles/galton.dir/iopegs.cpp.o"

# External object files for target galton
galton_EXTERNAL_OBJECTS =

galton: CMakeFiles/galton.dir/main.cpp.o
galton: CMakeFiles/galton.dir/board.cpp.o
galton: CMakeFiles/galton.dir/iopegs.cpp.o
galton: CMakeFiles/galton.dir/build.make
galton: /opt/homebrew/lib/libsfml-graphics.2.6.0.dylib
galton: /opt/homebrew/lib/libsfml-window.2.6.0.dylib
galton: /opt/homebrew/lib/libsfml-system.2.6.0.dylib
galton: CMakeFiles/galton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liamcavini/programming/galton_board/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable galton"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/galton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/galton.dir/build: galton
.PHONY : CMakeFiles/galton.dir/build

CMakeFiles/galton.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/galton.dir/cmake_clean.cmake
.PHONY : CMakeFiles/galton.dir/clean

CMakeFiles/galton.dir/depend:
	cd /Users/liamcavini/programming/galton_board/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liamcavini/programming/galton_board /Users/liamcavini/programming/galton_board /Users/liamcavini/programming/galton_board/build /Users/liamcavini/programming/galton_board/build /Users/liamcavini/programming/galton_board/build/CMakeFiles/galton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/galton.dir/depend
