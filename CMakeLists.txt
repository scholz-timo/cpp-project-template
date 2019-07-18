cmake_minimum_required (VERSION 3.1)
project (GameEngine)

set (GameEngine_VERSION_MAJOR 0)
set (GameEngine_VERSION_MINOR 0)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

configure_file (
	"${PROJECT_SOURCE_DIR}/src/configuration.hh.in"
	"${PROJECT_SOURCE_DIR}/src/configuration.hh"
)

include_directories("${PROJECT_BINARY_DIR}/src")
add_executable(run src/main.cxx)