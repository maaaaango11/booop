<<<<<<< HEAD
# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\wrk\life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\wrk\life\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/life.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/life.dir/flags.make

CMakeFiles/life.dir/main.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/life.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\main.cpp.obj -c D:\wrk\life\main.cpp

CMakeFiles/life.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\main.cpp > CMakeFiles\life.dir\main.cpp.i

CMakeFiles/life.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\main.cpp -o CMakeFiles\life.dir\main.cpp.s

CMakeFiles/life.dir/Cell.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/Cell.cpp.obj: ../Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/life.dir/Cell.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\Cell.cpp.obj -c D:\wrk\life\Cell.cpp

CMakeFiles/life.dir/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/Cell.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\Cell.cpp > CMakeFiles\life.dir\Cell.cpp.i

CMakeFiles/life.dir/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/Cell.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\Cell.cpp -o CMakeFiles\life.dir\Cell.cpp.s

CMakeFiles/life.dir/Field.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/Field.cpp.obj: ../Field.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/life.dir/Field.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\Field.cpp.obj -c D:\wrk\life\Field.cpp

CMakeFiles/life.dir/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/Field.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\Field.cpp > CMakeFiles\life.dir\Field.cpp.i

CMakeFiles/life.dir/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/Field.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\Field.cpp -o CMakeFiles\life.dir\Field.cpp.s

CMakeFiles/life.dir/Commando.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/Commando.cpp.obj: ../Commando.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/life.dir/Commando.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\Commando.cpp.obj -c D:\wrk\life\Commando.cpp

CMakeFiles/life.dir/Commando.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/Commando.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\Commando.cpp > CMakeFiles\life.dir\Commando.cpp.i

CMakeFiles/life.dir/Commando.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/Commando.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\Commando.cpp -o CMakeFiles\life.dir\Commando.cpp.s

CMakeFiles/life.dir/UI.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/UI.cpp.obj: ../UI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/life.dir/UI.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\UI.cpp.obj -c D:\wrk\life\UI.cpp

CMakeFiles/life.dir/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/UI.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\UI.cpp > CMakeFiles\life.dir\UI.cpp.i

CMakeFiles/life.dir/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/UI.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\UI.cpp -o CMakeFiles\life.dir\UI.cpp.s

CMakeFiles/life.dir/GameField.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/GameField.cpp.obj: ../GameField.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/life.dir/GameField.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\GameField.cpp.obj -c D:\wrk\life\GameField.cpp

CMakeFiles/life.dir/GameField.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/GameField.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\GameField.cpp > CMakeFiles\life.dir\GameField.cpp.i

CMakeFiles/life.dir/GameField.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/GameField.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\GameField.cpp -o CMakeFiles\life.dir\GameField.cpp.s

# Object files for target life
life_OBJECTS = \
"CMakeFiles/life.dir/main.cpp.obj" \
"CMakeFiles/life.dir/Cell.cpp.obj" \
"CMakeFiles/life.dir/Field.cpp.obj" \
"CMakeFiles/life.dir/Commando.cpp.obj" \
"CMakeFiles/life.dir/UI.cpp.obj" \
"CMakeFiles/life.dir/GameField.cpp.obj"

# External object files for target life
life_EXTERNAL_OBJECTS =

life.exe: CMakeFiles/life.dir/main.cpp.obj
life.exe: CMakeFiles/life.dir/Cell.cpp.obj
life.exe: CMakeFiles/life.dir/Field.cpp.obj
life.exe: CMakeFiles/life.dir/Commando.cpp.obj
life.exe: CMakeFiles/life.dir/UI.cpp.obj
life.exe: CMakeFiles/life.dir/GameField.cpp.obj
life.exe: CMakeFiles/life.dir/build.make
life.exe: CMakeFiles/life.dir/linklibs.rsp
life.exe: CMakeFiles/life.dir/objects1.rsp
life.exe: CMakeFiles/life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable life.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\life.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/life.dir/build: life.exe

.PHONY : CMakeFiles/life.dir/build

CMakeFiles/life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\life.dir\cmake_clean.cmake
.PHONY : CMakeFiles/life.dir/clean

CMakeFiles/life.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\wrk\life D:\wrk\life D:\wrk\life\cmake-build-debug D:\wrk\life\cmake-build-debug D:\wrk\life\cmake-build-debug\CMakeFiles\life.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/life.dir/depend

=======
# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\wrk\life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\wrk\life\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/life.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/life.dir/flags.make

CMakeFiles/life.dir/main.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/life.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\main.cpp.obj -c D:\wrk\life\main.cpp

CMakeFiles/life.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\main.cpp > CMakeFiles\life.dir\main.cpp.i

CMakeFiles/life.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\main.cpp -o CMakeFiles\life.dir\main.cpp.s

CMakeFiles/life.dir/Cell.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/Cell.cpp.obj: ../Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/life.dir/Cell.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\Cell.cpp.obj -c D:\wrk\life\Cell.cpp

CMakeFiles/life.dir/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/Cell.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\Cell.cpp > CMakeFiles\life.dir\Cell.cpp.i

CMakeFiles/life.dir/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/Cell.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\Cell.cpp -o CMakeFiles\life.dir\Cell.cpp.s

CMakeFiles/life.dir/Field.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/Field.cpp.obj: ../Field.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/life.dir/Field.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\Field.cpp.obj -c D:\wrk\life\Field.cpp

CMakeFiles/life.dir/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/Field.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\Field.cpp > CMakeFiles\life.dir\Field.cpp.i

CMakeFiles/life.dir/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/Field.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\Field.cpp -o CMakeFiles\life.dir\Field.cpp.s

CMakeFiles/life.dir/Commando.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/Commando.cpp.obj: ../Commando.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/life.dir/Commando.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\Commando.cpp.obj -c D:\wrk\life\Commando.cpp

CMakeFiles/life.dir/Commando.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/Commando.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\Commando.cpp > CMakeFiles\life.dir\Commando.cpp.i

CMakeFiles/life.dir/Commando.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/Commando.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\Commando.cpp -o CMakeFiles\life.dir\Commando.cpp.s

CMakeFiles/life.dir/UI.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/UI.cpp.obj: ../UI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/life.dir/UI.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\UI.cpp.obj -c D:\wrk\life\UI.cpp

CMakeFiles/life.dir/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/UI.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\UI.cpp > CMakeFiles\life.dir\UI.cpp.i

CMakeFiles/life.dir/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/UI.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\UI.cpp -o CMakeFiles\life.dir\UI.cpp.s

CMakeFiles/life.dir/GameField.cpp.obj: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/GameField.cpp.obj: ../GameField.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/life.dir/GameField.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\life.dir\GameField.cpp.obj -c D:\wrk\life\GameField.cpp

CMakeFiles/life.dir/GameField.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/life.dir/GameField.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\life\GameField.cpp > CMakeFiles\life.dir\GameField.cpp.i

CMakeFiles/life.dir/GameField.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/life.dir/GameField.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\life\GameField.cpp -o CMakeFiles\life.dir\GameField.cpp.s

# Object files for target life
life_OBJECTS = \
"CMakeFiles/life.dir/main.cpp.obj" \
"CMakeFiles/life.dir/Cell.cpp.obj" \
"CMakeFiles/life.dir/Field.cpp.obj" \
"CMakeFiles/life.dir/Commando.cpp.obj" \
"CMakeFiles/life.dir/UI.cpp.obj" \
"CMakeFiles/life.dir/GameField.cpp.obj"

# External object files for target life
life_EXTERNAL_OBJECTS =

life.exe: CMakeFiles/life.dir/main.cpp.obj
life.exe: CMakeFiles/life.dir/Cell.cpp.obj
life.exe: CMakeFiles/life.dir/Field.cpp.obj
life.exe: CMakeFiles/life.dir/Commando.cpp.obj
life.exe: CMakeFiles/life.dir/UI.cpp.obj
life.exe: CMakeFiles/life.dir/GameField.cpp.obj
life.exe: CMakeFiles/life.dir/build.make
life.exe: CMakeFiles/life.dir/linklibs.rsp
life.exe: CMakeFiles/life.dir/objects1.rsp
life.exe: CMakeFiles/life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\wrk\life\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable life.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\life.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/life.dir/build: life.exe

.PHONY : CMakeFiles/life.dir/build

CMakeFiles/life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\life.dir\cmake_clean.cmake
.PHONY : CMakeFiles/life.dir/clean

CMakeFiles/life.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\wrk\life D:\wrk\life D:\wrk\life\cmake-build-debug D:\wrk\life\cmake-build-debug D:\wrk\life\cmake-build-debug\CMakeFiles\life.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/life.dir/depend

>>>>>>> 476c3f8679e3a053f7623a934196f91509dd2542