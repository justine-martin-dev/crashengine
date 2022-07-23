
cmake_minimum_required (VERSION 3.23)
project(CrashEngine VERSION 0.0.0 LANGUAGES CXX)

add_subdirectory(vendors/catch2)
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glm)

# Crashengine
add_library(CrashEngine src/CrashEngine/crashengine.cpp)

target_include_directories(CrashEngine 
	PUBLIC 
		include/CrashEngine)

set_target_properties(CrashEngine PROPERTIES CXX_STANDARD 17)

# Default handlers
add_library(CrashEngine-default-handlers src/default-handlers/fucking_imp.cpp
	                                     src/default-handlers/glfw_handler.cpp)

target_include_directories(CrashEngine-default-handlers
	PUBLIC 
		include/default-handlers
		vendors/stb 
		vendors/glad/include)

set_target_properties(CrashEngine-default-handlers PROPERTIES POSITION_INDEPENDENT_CODE True)

target_link_libraries(CrashEngine-default-handlers CrashEngine glm glfw)
set_target_properties(CrashEngine-default-handlers PROPERTIES CXX_STANDARD 17)

# Demo
add_executable(demo src/demo/main.cpp)

target_include_directories(demo 
	PUBLIC 
		demo/include)

target_link_libraries(demo CrashEngine CrashEngine-default-handlers)
set_target_properties(demo PROPERTIES CXX_STANDARD 17)

# Tests
add_executable(tests 
	test/TestCase.cpp)

target_link_libraries(tests Catch2WithMain CrashEngine CrashEngine-default-handlers)
set_target_properties(tests PROPERTIES CXX_STANDARD 17)

include(CTest)
include(Catch)
catch_discover_tests(tests)
