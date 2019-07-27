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

set (py_cmd "change_required_cxx_version.py")

execute_process(
	COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/${py_cmd}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-src
)

add_subdirectory(
	${CMAKE_CURRENT_BINARY_DIR}/googletest-src
	${CMAKE_CURRENT_BINARY_DIR}/googletest-build
	EXCLUDE_FROM_ALL
)

if (CMAKE_VERSION VERSION_LESS 2.8.11)
	include_directories("${gtest_SOURCE_DIR}/include")
endif()