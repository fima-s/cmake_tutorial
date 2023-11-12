cmake_minimum_required(VERSION 3.15)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(tutorial_VERSION_MAJOR 2)
set(tutorial_VERSION_MINOR 2)
set(tutorial_VERSION_PATCH 66)

# Работает, если прокидываем с самого верхнего уровня
option(USE_MYMATH "Use tutorial provided math implementation" ON)

project (Step2_Adding_Library_Project
        VERSION ${tutorial_VERSION_MAJOR}.${tutorial_VERSION_MINOR}.${tutorial_VERSION_PATCH})

# set это создание переменной с которой ассоциируется следующий набор сорс файлов
set(    SOURCES
        ${PROJECT_SOURCE_DIR}/src/tutorial.cpp # или CMAKE_SOURCE_DIR
        )

# Работает, если прокидываем с самого верхнего уровня
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF) # std=c++11

configure_file(
        ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h.in
        ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h)

# Добавляет поддиректорию в проект.
# Поддиректория (в данном случае MathFunctions) указывает директорию
# в которой находится CMakeLists файл и сорцы
# Формально здесь используется относительный путь, можно просто папку писать
add_subdirectory(${CMAKE_SOURCE_DIR}/MathFunctions)

add_executable(Step2_Adding_Library_Project ${SOURCES})

# Здесь мы добавляем библиотеку MathFunctions к нашему проекту
target_link_libraries(Step2_Adding_Library_Project PUBLIC MathFunctions)

# Определяет иректории, которые нужно включить при компиляции указанного таргета
# помещается после add_executable() или add_library()
target_include_directories(Step2_Adding_Library_Project
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/MathFunctions/include
        )

#PRIVATE служит для того, чтобы указать какие элементы (исходники, библиотеки, цели)
#необходимы для сборки этой цели. Т.е. эта цель зависима от этих элементов, но другие
#цели, которые будут использовать эту цель в качестве зависимости, не получат её
#зависимости транзитивно. Т.е. если цель A зависит от нашей цели Target, у которой
#в качестве приватной зависимости указана цель Dep, то A не будет зависеть от Dep,
#а Target будет использовать Dep при сборке себя.
#
#INTERFACE служит для указания элементов, которые не нужны для сборки этой цели,
#но они должны быть «прокинуты» для любой цели, которая данную цель указывает в
#качестве зависимости. Т.е. если цель A зависит от нашей цели Target, у которой
#в качестве интерфейсной зависимости указана цель Dep, то A будет зависеть от
#Dep, но Target не будет использовать Dep при сборке себя.
#
#PUBLIC аналогичен связке INTERFACE и PRIVATE. Т.е. если цель A зависит от
#нашей цели Target, у которой в качестве публичной зависимости указана цель
#Dep, то A будет зависеть от Dep, а Target будет использовать Dep при сборке себя.
#
#Прибегать к ним стоит тогда, когда нужно. Это сравнительно новые модификаторы,
#которые лучше всего раскрывают себя при разработке библиотек. Т.е. они позволяют
#чётко разграничить, что мы показываем миру и что от чего зависит.
#Для себя можно взять за правило использовать PRIVATE по умолчанию,
#прибегая к другим модификаторам только тогда, когда они действительно необходимы.


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
