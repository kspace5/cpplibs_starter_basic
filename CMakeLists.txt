# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.

# Ref: https://cmake.org/examples/
cmake_minimum_required (VERSION 3.0)

set(PROJECT_NAME grpc-lab)
project (${PROJECT_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../sample_proto)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../grpc/include)

# find_library Syntax 
# find_library(MYLIB NAMES name1 name2 PATHS dir1 dir2)
# message(${MYLIB})

# Find required external libraries
find_library(protobuf NAMES libprotobuf PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../grpc/build_win64/third_party/protobuf/Release)
message("find_library:${protobuf}:done")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/")

# Add sub directories
add_subdirectory (cpplib_abc01_static)
add_subdirectory (cpplib_xyc01_shared)
add_subdirectory (demo)
