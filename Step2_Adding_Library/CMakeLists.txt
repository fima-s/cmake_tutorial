cmake_minimum_required(VERSION 3.15)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(tutorial_VERSION_MAJOR 2)
set(tutorial_VERSION_MINOR 2)
set(tutorial_VERSION_PATCH 66)

project (Step2_Adding_Library_Project
        VERSION ${tutorial_VERSION_MAJOR}.${tutorial_VERSION_MINOR}.${tutorial_VERSION_PATCH})

# set это создание переменной с которой ассоциируется следующий набор сорс файлов
set(    SOURCES
        ${PROJECT_SOURCE_DIR}/src/tutorial.cpp # или CMAKE_SOURCE_DIR
        )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file( ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h.in
        ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h)

add_subdirectory(MathFunctions ${PROJECT_SOURCE_DIR}/MathFunctions)

add_executable(Step2_Adding_Library_Project ${SOURCES})

target_link_libraries(Step2_Adding_Library_Project PUBLIC MathFunctions)

target_include_directories(Step2_Adding_Library_Project
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/MathFunctions/include
        )

##################################
# cd build
# cmake ../
# cmake --build .
##################################

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
