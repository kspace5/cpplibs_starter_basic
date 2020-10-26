# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.

file(GLOB_RECURSE HEADER_FILES ./*.h)
file(GLOB_RECURSE SRC_FILES ./*.cpp)

add_executable (demo ${HEADER_FILES} ${SRC_FILES})

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (demo PUBLIC abc)
#target_link_libraries (demo PUBLIC ${client_x1})
target_link_libraries (demo PRIVATE xyc)
