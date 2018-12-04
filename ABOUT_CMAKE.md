About the CMake
===============

This is the cmake configuration file for the hasprocess SystemC project.

This file works with SystemV versions 2.3.2 and later, which have support for
cmake and specify SystemC_CXX_STANDARD.

A tutorial and documentation for cmake can be found at
<https://cmake.org/cmake-tutorial/>.

Note: A number of entries are commented out because they are not always
      needed. Uncomment as you see fit.

Requirements
------------

This file must be named "CMakeLists.txt", and is the starting point for
cmake configuration.

Define SYSTEMC_HOME to point to install directory of SystemC (not source)

How to use
----------

Assuming you are running under Linux here are some simple instructions:

1. Create somewhere to build and run the project. You can do this in the same
   directory as this file and the source code; however, it will add some
   clutter.

   Specifically, it will add:

   - `CMakeCache.txt` -- cached values of configuration
   - `CmakeFiles/` -- sub-directory for all secondary files
   - `cmake_install.cmake` -- file to use this directories `cmake` elsewhere
   - Makefile -- starting place for all make activity

   To avoid the clutter, create a sub-directory and change location to it:

   ```sh
   mkdir -p build
   cd build
   ```

2. Configure your project

   ```sh
   cmake ..
   ```

3. Modify source code as needed

4. Build the code

   ```sh
   make
   ```

5. If unsuccessful, examine the output and go back to step 3.

6. Execute the resultant executable

   ```sh
   ./hasprocess.x
   ```

7. Did it work? If unsuccessful, examine the output and go back to step 3.

### end vim:tw=80
