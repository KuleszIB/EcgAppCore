# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projekty\libs\quiet-dsp-win

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projekty\EcgAppCoreDADM

# Include any dependencies generated for this target.
include sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/depend.make

# Include the progress variables for this target.
include sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/progress.make

# Include the compile flags for this target's objects.
include sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/flags.make

sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.obj: sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/flags.make
sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.obj: sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/includes_C.rsp
sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.obj: C:/Projekty/libs/quiet-dsp-win/sandbox/fecsoft_hamming128_gentab.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projekty\EcgAppCoreDADM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.obj"
	cd /d C:\Projekty\EcgAppCoreDADM\sandbox && C:\Qt\Qt5.11.2\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sandbox_fecsoft_hamming128_gentab.dir\fecsoft_hamming128_gentab.c.obj   -c C:\Projekty\libs\quiet-dsp-win\sandbox\fecsoft_hamming128_gentab.c

sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.i"
	cd /d C:\Projekty\EcgAppCoreDADM\sandbox && C:\Qt\Qt5.11.2\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projekty\libs\quiet-dsp-win\sandbox\fecsoft_hamming128_gentab.c > CMakeFiles\sandbox_fecsoft_hamming128_gentab.dir\fecsoft_hamming128_gentab.c.i

sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.s"
	cd /d C:\Projekty\EcgAppCoreDADM\sandbox && C:\Qt\Qt5.11.2\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projekty\libs\quiet-dsp-win\sandbox\fecsoft_hamming128_gentab.c -o CMakeFiles\sandbox_fecsoft_hamming128_gentab.dir\fecsoft_hamming128_gentab.c.s

# Object files for target sandbox_fecsoft_hamming128_gentab
sandbox_fecsoft_hamming128_gentab_OBJECTS = \
"CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.obj"

# External object files for target sandbox_fecsoft_hamming128_gentab
sandbox_fecsoft_hamming128_gentab_EXTERNAL_OBJECTS =

sandbox/fecsoft_hamming128_gentab.exe: sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/fecsoft_hamming128_gentab.c.obj
sandbox/fecsoft_hamming128_gentab.exe: sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/build.make
sandbox/fecsoft_hamming128_gentab.exe: libliquid.dll.a
sandbox/fecsoft_hamming128_gentab.exe: sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/linklibs.rsp
sandbox/fecsoft_hamming128_gentab.exe: sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/objects1.rsp
sandbox/fecsoft_hamming128_gentab.exe: sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projekty\EcgAppCoreDADM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable fecsoft_hamming128_gentab.exe"
	cd /d C:\Projekty\EcgAppCoreDADM\sandbox && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sandbox_fecsoft_hamming128_gentab.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/build: sandbox/fecsoft_hamming128_gentab.exe

.PHONY : sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/build

sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/clean:
	cd /d C:\Projekty\EcgAppCoreDADM\sandbox && $(CMAKE_COMMAND) -P CMakeFiles\sandbox_fecsoft_hamming128_gentab.dir\cmake_clean.cmake
.PHONY : sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/clean

sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projekty\libs\quiet-dsp-win C:\Projekty\libs\quiet-dsp-win\sandbox C:\Projekty\EcgAppCoreDADM C:\Projekty\EcgAppCoreDADM\sandbox C:\Projekty\EcgAppCoreDADM\sandbox\CMakeFiles\sandbox_fecsoft_hamming128_gentab.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : sandbox/CMakeFiles/sandbox_fecsoft_hamming128_gentab.dir/depend

