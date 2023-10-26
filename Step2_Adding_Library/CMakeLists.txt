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

configure_file( ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h.in
        ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h)

add_executable(Step1_project ${SOURCES})

target_include_directories(Step1_project
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h
        )

##################################
# cd build
# cmake ../
# cmake --build .
##################################


