# source: https://github.com/google/googletest/tree/master/googletest#incorporating-into-an-existing-cmake-project

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(
	COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . 
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
)

if (result)
	message (FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(
	COMMAND ${CMAKE_COMMAND} --build . 
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download
)

if (result)
	message (FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


include(FindPythonInterp)
if(PYTHONINTERP_FOUND)
else(PYTHONINTERP_FOUND)
	MESSAGE(FATAL_ERROR "Unable to locate Python Interpreter.")
endif(PYTHONINTERP_FOUND)

# added this for compatibility with msvc.
configure_file(change_required_cxx_version.py.in change_required_cxx_version.py)
execute_process(
	COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/change_required_cxx_version.py
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-src
)


# added this for test collection.
configure_file(collect_tests.py.in collect_tests.py)
execute_process (
	COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/collect_tests.py
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/tests
)

add_subdirectory(
	${CMAKE_CURRENT_BINARY_DIR}/googletest-src
	${CMAKE_CURRENT_BINARY_DIR}/googletest-build
	EXCLUDE_FROM_ALL
)

if (CMAKE_VERSION VERSION_LESS 2.8.11)
	include_directories("${gtest_SOURCE_DIR}/include")
endif()