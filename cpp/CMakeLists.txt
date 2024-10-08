cmake_minimum_required (VERSION 3.10)
project ("GithubActions")

set (CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD 17)

if(MSVC)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /EHsc")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()
file(GLOB_RECURSE SOURCEFILES src/*)
add_library(Library ${SOURCEFILES})
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


# Download and unpack googletest at configure time
configure_file(ext/googletest/CMakeLists.txt.in ${CMAKE_CURRENT_BINARY_DIR}/ext/googletest/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
RESULT_VARIABLE result
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ext/googletest/googletest-download )
if(result)
	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
RESULT_VARIABLE result
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ext/googletest/googletest-download )
if(result)
	message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/ext/googletest/googletest-src
				 ${CMAKE_CURRENT_BINARY_DIR}/ext/googletest/googletest-build
				 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
	include_directories("${gtest_SOURCE_DIR}/include")
endif()

file(GLOB_RECURSE UNITTESTFILES tests/*)

add_executable(unittests ${UNITTESTFILES})

target_link_libraries(unittests gtest_main)
target_link_libraries(unittests gmock)
target_link_libraries(unittests Library)
