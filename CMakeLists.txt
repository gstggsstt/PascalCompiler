cmake_minimum_required(VERSION 3.16)
project(SPL)

set(CMAKE_CXX_STANDARD 17)
find_package(LLVM REQUIRED CONFIG)

execute_process(COMMAND sh flex.sh)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
        COMMAND flex ${CMAKE_CURRENT_BINARY_DIR}/SPL.l)

# Now build our tools
add_executable(SPL main.cpp ASTNode.cpp ASTNode.h)
add_executable(SPL-parser lex.yy.c)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(SPL ${llvm_libs})
