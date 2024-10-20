cmake_minimum_required(VERSION 3.15)
project(IML)

# Set CMake properties
set(CMAKE_CXX_STANDARD 17)
cmake_policy(SET CMP0135 NEW)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set fields
set(TESTDATA_SRC_DIR "${CMAKE_SOURCE_DIR}/tests/testdata")
set(TESTDATA_BUILD_DIR "${CMAKE_BINARY_DIR}/testdata")



# Find files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE TEST_SOURCES ${CMAKE_SOURCE_DIR}/tests/*.cpp)



# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
enable_testing()



# Add targets
add_library(IML STATIC ${SOURCES} ${HEADERS})
add_executable(IML_Test ${TEST_SOURCES})


# Linking tests with the main library and GoogleTest
target_link_libraries(IML_Test PRIVATE IML gtest gtest_main)

# Add tests to CTest
add_test(NAME IML_Test COMMAND IML_Test)

# Copy the test data to the binary directory
add_custom_command(
    TARGET IML_Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${TESTDATA_SRC_DIR} ${TESTDATA_BUILD_DIR}
)