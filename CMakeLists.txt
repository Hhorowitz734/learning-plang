cmake_minimum_required(VERSION 3.20)
project(plang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# MAIN EXECUTABLE
add_executable(plang
  src/main.cpp
  src/lexer.cpp
  src/token.cpp
)

target_include_directories(plang PRIVATE src)

# Strong warnings 
if (MSVC)
  target_compile_options(plang PRIVATE /W4 /permissive-)
else()
  target_compile_options(plang PRIVATE
    -Wall -Wextra -Wpedantic
    -Wconversion -Wsign-conversion
  )
endif()

# TESTS 
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(plang_tests
  tests/lexer_tests.cpp
  src/lexer.cpp
  src/token.cpp
)

target_include_directories(plang_tests PRIVATE src)
target_link_libraries(plang_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(plang_tests)
