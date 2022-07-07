
cmake_minimum_required (VERSION 3.8)
project(crashengine)

set (CMAKE_CXX_STANDARD 17)

# Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Crashengine
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
FILE(GLOB_RECURSE SRC_FILES_CRASHENGINE src/*.cpp include/*.hpp)
add_library(crashengine ${SRC_FILES_CRASHENGINE})
target_link_libraries(crashengine ${CONAN_LIBS})

# Demo
project(demo)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/demo/include/)
FILE(GLOB_RECURSE SRC_FILES_DEMO demo/src/*.cpp demo/include/*.hpp)
add_executable(demo ${SRC_FILES_DEMO})
target_link_libraries(demo crashengine)
