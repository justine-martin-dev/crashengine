
cmake_minimum_required (VERSION 3.23)
project(CrashEngine VERSION 0.0.0 LANGUAGES CXX)

add_subdirectory(vendors/catch2)
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glm)

# Crashengine
add_library(CrashEngine 
	include/CrashEngine/glfw.hpp src/CrashEngine/glfw.cpp
	include/CrashEngine/module.hpp src/CrashEngine/module.cpp
	include/CrashEngine/window.hpp src/CrashEngine/window.cpp)

target_include_directories(CrashEngine 
	PUBLIC 
		include/ 
		vendors/stb 
		vendors/glad/include)

target_link_libraries(CrashEngine glm glfw)
set_target_properties(CrashEngine PROPERTIES CXX_STANDARD 17)

# Demo
add_executable(demo 
	demo/src/main.cpp)

target_include_directories(demo 
	PUBLIC 
		demo/include/)

target_link_libraries(demo CrashEngine)
set_target_properties(demo PROPERTIES CXX_STANDARD 17)

# Tests
add_executable(tests 
	test/TestCase.cpp)

target_link_libraries(tests Catch2WithMain CrashEngine)
set_target_properties(tests PROPERTIES CXX_STANDARD 17)

include(CTest)
include(Catch)
catch_discover_tests(tests)