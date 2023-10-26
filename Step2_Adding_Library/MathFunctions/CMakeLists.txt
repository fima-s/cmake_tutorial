cmake_minimum_required(VERSION 3.1)

# TODO 14: Remove mysqrt.cxx from the list of sources

# TODO 1: Add a library called MathFunctions with sources MathFunctions.cxx
# and mysqrt.cxx
# Hint: You will need the add_library command
set(SOURCES src/MathFunctions.cpp
            src/mysqrt.cpp)

project(MathFunctions)

add_library(MathFunctions STATIC ${SOURCES})

target_include_directories( MathFunctions PRIVATE ${PROJECT_SOURCE_DIR}/include)

# TODO 7: Create a variable USE_MYMATH using option and set default to ON

# TODO 8: If USE_MYMATH is ON, use target_compile_definitions to pass
# USE_MYMATH as a precompiled definition to our source files

# TODO 12: When USE_MYMATH is ON, add a library for SqrtLibrary with
# source mysqrt.cxx

# TODO 13: When USE_MYMATH is ON, link SqrtLibrary to the MathFunctions Library

## The root source directory
#message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
##
## The current source directory if using sub-projects and directories.
#message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
##
## The source directory of the current cmake project.
#message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
##
##The root binary / build directory. This is the directory where you ran the cmake command.
## У Clion по умолчанию это cmake-build-debug
#message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
##
## The build directory you are currently in.
#message("CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
##
## The build directory for the current project.
#message("PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")