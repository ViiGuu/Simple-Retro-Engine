Working with the project on a new pc:
- When cloning the repository you need to first create a build directory in the project folder before building the project with Cmake.
- Make sure VCPKG is installed on the system. Set VCPKG_ROOT and Path in Environment Variables.

Adding tests:
This project uses Google Test as a testing framework. To add additional tests, add the test cpp file, then update the CMakeLists TEST_FILES before building the project.
