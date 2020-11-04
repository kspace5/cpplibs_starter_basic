# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.

# Ref: https://cmake.org/examples/
cmake_minimum_required (VERSION 3.0)

set(PROJECT_NAME grpc-lab)
project (${PROJECT_NAME})

set(FLEX_HOME ${CMAKE_CURRENT_SOURCE_DIR}/../FleX)
set(GLM_HOME ${CMAKE_CURRENT_SOURCE_DIR}/glm)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../sample_proto)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../grpc/include)
include_directories(${FLEX_HOME}/include)
include_directories(${GLM_HOME})

# find_library Syntax 
# find_library(MYLIB NAMES name1 name2 PATHS dir1 dir2)
# message(${MYLIB})

# Find required external libraries
find_library(NvFlexReleaseCUDA NAMES NvFlexReleaseCUDA_x64 PATHS ${FLEX_HOME}/lib/win64)
message("find_library:${NvFlexReleaseCUDA}:done")
find_library(NvFlexExtReleaseCUDA NAMES NvFlexExtReleaseCUDA_x64 PATHS ${FLEX_HOME}/lib/win64)
message("find_library:${NvFlexExtReleaseCUDA}:done")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")

# Add sub directories
add_subdirectory (cpplib_abc01_static)
add_subdirectory (cpplib_xyc01_shared)
add_subdirectory (demo)
