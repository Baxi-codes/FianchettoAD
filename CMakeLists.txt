cmake_minimum_required(VERSION 3.5)
project(FianchettoAD)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g")

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/includes)

# Find and include Flex
find_package(FLEX REQUIRED)

# Define the target for the Flex output
FLEX_TARGET(LexerScanner src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.yy.cpp)

# Add source files
set(SOURCES
    src/lexer.cpp
    ${FLEX_LexerScanner_OUTPUTS}
    tests/lexer_test.cpp
)

# Add executable
add_executable(FianchettoAD ${SOURCES})