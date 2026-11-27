cmake_minimum_required(VERSION 3.20)
project(cpp_prep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

# -DSANITIZE=address,undefined   or   -DSANITIZE=thread
set(SANITIZE "" CACHE STRING "Sanitizers to enable")
if(SANITIZE)
  add_compile_options(-fsanitize=${SANITIZE} -fno-omit-frame-pointer -g)
  add_link_options(-fsanitize=${SANITIZE})
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(basic_test tests/basic_test.cpp)
target_link_libraries(basic_test PRIVATE GTest::gtest_main)
gtest_discover_tests(basic_test)
