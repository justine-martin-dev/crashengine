cmake_minimum_required (VERSION 3.23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(CrashEngine VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(vendors/catch2)
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glm)

# Crashengine
add_library(CrashEngine 
	engine/src/CrashEngine/CrashEngine.cpp
	engine/src/CrashEngine/Entity.cpp
	engine/src/CrashEngine/logger.cpp
	engine/src/CrashEngine/Scene.cpp
	engine/src/CrashEngine/Texture.cpp)

target_include_directories(CrashEngine 
	PUBLIC 
		engine/include)

set_target_properties(CrashEngine PROPERTIES CXX_STANDARD 20)
target_link_libraries(CrashEngine glm)

# Default handlers
add_library(CrashEngine-default-handlers 
	default-handlers/src/CrashEngine/default-handlers/fucking_imp.cpp
	default-handlers/src/CrashEngine/default-handlers/glfw.cpp
	default-handlers/src/CrashEngine/default-handlers/opengl.cpp
	default-handlers/src/CrashEngine/default-handlers/opengl/OpenGlBuffer.cpp
	default-handlers/src/CrashEngine/default-handlers/opengl/OpenGlMesh.cpp
	default-handlers/src/CrashEngine/default-handlers/opengl/OpenGlShader.cpp
	default-handlers/src/CrashEngine/default-handlers/opengl/OpenGlTexture.cpp)

target_include_directories(CrashEngine-default-handlers  
	PUBLIC 
		default-handlers/include
		vendors/stb 
		vendors/glad/include)

set_target_properties(CrashEngine-default-handlers PROPERTIES POSITION_INDEPENDENT_CODE True)

target_link_libraries(CrashEngine-default-handlers CrashEngine glm glfw)
set_target_properties(CrashEngine-default-handlers PROPERTIES CXX_STANDARD 17)

# Demo
add_executable(demo 
	demo/src/main.cpp
	demo/src/MainScene.cpp)

target_include_directories(demo 
	PUBLIC 
		demo/include)

target_link_libraries(demo CrashEngine CrashEngine-default-handlers)
set_target_properties(demo PROPERTIES CXX_STANDARD 17)

add_custom_command(TARGET demo PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/demo/assets/ $<TARGET_FILE_DIR:demo>)

# Tests
add_executable(tests 
	test/TestCase.cpp)

target_link_libraries(tests Catch2WithMain CrashEngine CrashEngine-default-handlers)
set_target_properties(tests PROPERTIES CXX_STANDARD 17)

include(CTest)
include(Catch)
catch_discover_tests(tests)
