cmake_minimum_required(VERSION 3.16)
project(SPL)

set(CMAKE_CXX_STANDARD 17)
find_package(LLVM REQUIRED CONFIG)
find_package(BISON)
find_package(FLEX)

BISON_TARGET(parser SPL.y ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp)
FLEX_TARGET(lexer SPL.l ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp)

ADD_FLEX_BISON_DEPENDENCY(lexer parser)

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(${LLVM_DEFINITIONS})

# Now build our tools
add_executable(SPL main.cpp ASTNode.cpp ASTNode.h NodeTypes.h SystemCall.h SystemCall.cpp ${BISON_parser_OUTPUTS} ${FLEX_lexer_OUTPUTS})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader mcjit native asmparser)


# Link against LLVM libraries
find_library(LEX_LIB l)
target_link_libraries(SPL ${llvm_libs} ${LEX_LIB})
