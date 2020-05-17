cmake_minimum_required(VERSION 3.10)
project(fibonacci_num CXX)

# Set the searching location for cmake 'include' locations
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(c++-standards)
include(formatting)
include(sanitizers)
include(tools)
include(prepare_catch)

# Require C++11
cxx_11()

# Tools
file(GLOB_RECURSE SOURCE_FILES src/*.[hc] src/*.[hc]pp)
file(GLOB_RECURSE TEST_FILES test/*.[hc] test/*.[hc]pp)

set(ALL_FILES)
list(APPEND ALL_FILES ${SOURCE_FILES} ${TEST_FILES})

clang_format(format ${ALL_FILES})

cmake_format(cmake-format ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
             CMakeLists.txt)

clang_tidy(-format-style=file -checks=* -header-filter='${CMAKE_SOURCE_DIR}/*')
include_what_you_use(-Xiwyu)
cppcheck(
  --enable=warning,performance,portability,missingInclude
  --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
  --suppress=missingIncludeSystem --quiet --verbose --force)

enable_testing()

set(BUILD_TESTS ON)
prepare_catch()

# Build project
list(FILTER SOURCE_FILES EXCLUDE REGEX "^.*/src/main.cpp$")

add_library(${CMAKE_PROJECT_NAME}_library OBJECT ${SOURCE_FILES})

add_executable(${CMAKE_PROJECT_NAME} $<TARGET_OBJECTS:${CMAKE_PROJECT_NAME}_library> src/main.cpp)

# Build tests

add_executable(${CMAKE_PROJECT_NAME}_test ${TEST_FILES} $<TARGET_OBJECTS:${CMAKE_PROJECT_NAME}_library>)
target_link_libraries(${CMAKE_PROJECT_NAME}_test catch)
get_target_property(TEST_EXECUTABLE ${CMAKE_PROJECT_NAME}_test OUTPUT_NAME)
add_test(NAME test COMMAND ${TEST_EXECUTABLE})
