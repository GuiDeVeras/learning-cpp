#VCMaker version
cmake_minimum_required(VERSION 3.20)

#Project's name
project(exercise LANGUAGES CXX)

#C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Flags
add_compile_options(-Wall -Wextra -Wpedantic)

#ON/OFF sanitizers
set(SANITIZE "" CACHE STRING "Sanitizers to enable") # create a variable, empty by default
if (SANITIZE)
	add_compile_options(-fsanitize=${SANITIZE})
	add_link_options(-fsanitize=${SANITIZE})
endif()

include (FetchContent)
FetchContent_Declare (
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip
	
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable (
	binary_search_test
	src/binary_search.cpp
	tests/binary_search_test.cpp
)

target_include_directories(
	binary_search_test
	PRIVATE
	include
)


target_link_libraries (
	binary_search_test
	PRIVATE
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(binary_search_test)
