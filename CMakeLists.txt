cmake_minimum_required(VERSION 3.5)
project(FianchettoAD)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/includes)

# Add source files
set(SOURCES
    src/parser/AST.cpp
)

# Add executable
add_executable(FianchettoAD ${SOURCES})