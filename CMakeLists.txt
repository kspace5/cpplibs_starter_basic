# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.

# Ref: https://cmake.org/examples/
cmake_minimum_required (VERSION 3.0)

set(PROJECT_NAME grpc-lab)
project (${PROJECT_NAME})

set(GLIB_DIR E:/mnt/spacerock/35_ENGINE_BASE_CYGNUS/A_GO_LAB/go_lab_starter/golib1)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../sample_proto)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../grpc/include)
include_directories(${GLIB_DIR})


# find_library Syntax 
# find_library(MYLIB NAMES name1 name2 PATHS dir1 dir2)
# message(${MYLIB})

# Find required external libraries
#find_library(protobuf NAMES libprotobuf PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../grpc/build_win64/third_party/protobuf/Release)
#message("find_library:${protobuf}:done")
#find_library(client_x1 NAMES fgproc.lib PATHS ${GLIB_DIR})
#message("find_library:${client_x1}:done")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")

# Add sub directories
add_subdirectory (cpplib_abc01_static)
add_subdirectory (cpplib_xyc01_shared)
add_subdirectory (demo)
