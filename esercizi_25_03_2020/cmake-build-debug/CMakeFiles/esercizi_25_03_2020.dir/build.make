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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/esercizi_25_03_2020.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/esercizi_25_03_2020.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/esercizi_25_03_2020.dir/flags.make

CMakeFiles/esercizi_25_03_2020.dir/main.cpp.obj: CMakeFiles/esercizi_25_03_2020.dir/flags.make
CMakeFiles/esercizi_25_03_2020.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/esercizi_25_03_2020.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\esercizi_25_03_2020.dir\main.cpp.obj -c "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\main.cpp"

CMakeFiles/esercizi_25_03_2020.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/esercizi_25_03_2020.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\main.cpp" > CMakeFiles\esercizi_25_03_2020.dir\main.cpp.i

CMakeFiles/esercizi_25_03_2020.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/esercizi_25_03_2020.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\main.cpp" -o CMakeFiles\esercizi_25_03_2020.dir\main.cpp.s

CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.obj: CMakeFiles/esercizi_25_03_2020.dir/flags.make
CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.obj: ../orario.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\esercizi_25_03_2020.dir\orario.cpp.obj -c "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\orario.cpp"

CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\orario.cpp" > CMakeFiles\esercizi_25_03_2020.dir\orario.cpp.i

CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\orario.cpp" -o CMakeFiles\esercizi_25_03_2020.dir\orario.cpp.s

# Object files for target esercizi_25_03_2020
esercizi_25_03_2020_OBJECTS = \
"CMakeFiles/esercizi_25_03_2020.dir/main.cpp.obj" \
"CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.obj"

# External object files for target esercizi_25_03_2020
esercizi_25_03_2020_EXTERNAL_OBJECTS =

esercizi_25_03_2020.exe: CMakeFiles/esercizi_25_03_2020.dir/main.cpp.obj
esercizi_25_03_2020.exe: CMakeFiles/esercizi_25_03_2020.dir/orario.cpp.obj
esercizi_25_03_2020.exe: CMakeFiles/esercizi_25_03_2020.dir/build.make
esercizi_25_03_2020.exe: CMakeFiles/esercizi_25_03_2020.dir/linklibs.rsp
esercizi_25_03_2020.exe: CMakeFiles/esercizi_25_03_2020.dir/objects1.rsp
esercizi_25_03_2020.exe: CMakeFiles/esercizi_25_03_2020.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable esercizi_25_03_2020.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\esercizi_25_03_2020.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/esercizi_25_03_2020.dir/build: esercizi_25_03_2020.exe

.PHONY : CMakeFiles/esercizi_25_03_2020.dir/build

CMakeFiles/esercizi_25_03_2020.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\esercizi_25_03_2020.dir\cmake_clean.cmake
.PHONY : CMakeFiles/esercizi_25_03_2020.dir/clean

CMakeFiles/esercizi_25_03_2020.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020" "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020" "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\cmake-build-debug" "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\cmake-build-debug" "C:\xampp\htdocs\Ahmed_php\C & C++\esercizi_25_03_2020\cmake-build-debug\CMakeFiles\esercizi_25_03_2020.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/esercizi_25_03_2020.dir/depend

