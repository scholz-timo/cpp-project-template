cmake_minimum_required (VERSION 3.1)

project (GameEngine)

# setup project configuration.

set (GameEngine_VERSION_MAJOR 0)
set (GameEngine_VERSION_MINOR 0)

# configure cmake variables.

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

set (TEST_EXTENSIONS "\".test.hpp\", \".test.hh\"")

# configure options.
option(TESTING "Build all tests." ON)
option(TESTING_ONLY "Build only the tests." OFF)

if (TESTING_ONLY)
	if (TESTING)
	else()
		set (TESTING ON)
	endif()
endif()

# configure add_sources makro
macro (add_sources)
    file (RELATIVE_PATH _relPath "${PROJECT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND SRCS "${_relPath}/${_src}")
        else()
            list (APPEND SRCS "${_src}")
        endif()
    endforeach()
    if (_relPath)
        # propagate SRCS to parent directory
        set (SRCS ${SRCS} PARENT_SCOPE)
    endif()
endmacro()

# install external sources.
add_subdirectory(ext)


add_subdirectory(src)
add_executable(run ${SRCS})


set_target_properties(run
	PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
)

if (TESTING)
	add_subdirectory(tests)
	target_link_libraries(run gtest_main)
endif()