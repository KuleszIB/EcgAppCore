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
include examples/CMakeFiles/examples_detector_cccf_example.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/examples_detector_cccf_example.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/examples_detector_cccf_example.dir/flags.make

examples/CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.obj: examples/CMakeFiles/examples_detector_cccf_example.dir/flags.make
examples/CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.obj: examples/CMakeFiles/examples_detector_cccf_example.dir/includes_C.rsp
examples/CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.obj: C:/Projekty/libs/quiet-dsp-win/examples/detector_cccf_example.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projekty\EcgAppCoreDADM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.obj"
	cd /d C:\Projekty\EcgAppCoreDADM\examples && C:\Qt\Qt5.11.2\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\examples_detector_cccf_example.dir\detector_cccf_example.c.obj   -c C:\Projekty\libs\quiet-dsp-win\examples\detector_cccf_example.c

examples/CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.i"
	cd /d C:\Projekty\EcgAppCoreDADM\examples && C:\Qt\Qt5.11.2\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projekty\libs\quiet-dsp-win\examples\detector_cccf_example.c > CMakeFiles\examples_detector_cccf_example.dir\detector_cccf_example.c.i

examples/CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.s"
	cd /d C:\Projekty\EcgAppCoreDADM\examples && C:\Qt\Qt5.11.2\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projekty\libs\quiet-dsp-win\examples\detector_cccf_example.c -o CMakeFiles\examples_detector_cccf_example.dir\detector_cccf_example.c.s

# Object files for target examples_detector_cccf_example
examples_detector_cccf_example_OBJECTS = \
"CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.obj"

# External object files for target examples_detector_cccf_example
examples_detector_cccf_example_EXTERNAL_OBJECTS =

examples/detector_cccf_example.exe: examples/CMakeFiles/examples_detector_cccf_example.dir/detector_cccf_example.c.obj
examples/detector_cccf_example.exe: examples/CMakeFiles/examples_detector_cccf_example.dir/build.make
examples/detector_cccf_example.exe: libliquid.dll.a
examples/detector_cccf_example.exe: examples/CMakeFiles/examples_detector_cccf_example.dir/linklibs.rsp
examples/detector_cccf_example.exe: examples/CMakeFiles/examples_detector_cccf_example.dir/objects1.rsp
examples/detector_cccf_example.exe: examples/CMakeFiles/examples_detector_cccf_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projekty\EcgAppCoreDADM\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable detector_cccf_example.exe"
	cd /d C:\Projekty\EcgAppCoreDADM\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\examples_detector_cccf_example.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/examples_detector_cccf_example.dir/build: examples/detector_cccf_example.exe

.PHONY : examples/CMakeFiles/examples_detector_cccf_example.dir/build

examples/CMakeFiles/examples_detector_cccf_example.dir/clean:
	cd /d C:\Projekty\EcgAppCoreDADM\examples && $(CMAKE_COMMAND) -P CMakeFiles\examples_detector_cccf_example.dir\cmake_clean.cmake
.PHONY : examples/CMakeFiles/examples_detector_cccf_example.dir/clean

examples/CMakeFiles/examples_detector_cccf_example.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projekty\libs\quiet-dsp-win C:\Projekty\libs\quiet-dsp-win\examples C:\Projekty\EcgAppCoreDADM C:\Projekty\EcgAppCoreDADM\examples C:\Projekty\EcgAppCoreDADM\examples\CMakeFiles\examples_detector_cccf_example.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/examples_detector_cccf_example.dir/depend

