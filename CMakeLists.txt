cmake_minimum_required(VERSION 3.5)
project(FianchettoAD)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb3 -rdynamic")


# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/includes)

# Find and include Flex
find_package(FLEX REQUIRED)

# Define the target for the Flex output
FLEX_TARGET(LexerScanner src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.yy.cpp)

# Find and configure LLVM
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})


# Link against the necessary LLVM components
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Add source files
set(SOURCES
    src/lexer.cpp
    src/ast.cpp
    src/parser.cpp
    src/symbol_table.cpp
    src/llvm_codegen.cpp
    src/utils/ast_printer.cpp
    tests/parser_test.cpp
    ${FLEX_LexerScanner_OUTPUTS}
)

# Add executable
add_executable(FianchettoAD ${SOURCES})
target_link_libraries(FianchettoAD ${llvm_libs})