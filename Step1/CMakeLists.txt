cmake_minimum_required(VERSION 3.15)
set(CMAKE_VERBOSE_MAKEFILE ON)
# Ни один cmake проект не создается без команды project можно без всего остального
# но project должен быть, если нету, то упадет с ошибкой
project (Step1_project)

# set это осздание переменной с которой ассоциируетяс следующий набор сорс файлов
set(    SOURCES
        ${PROJECT_SOURCE_DIR}/src/tutorial.cpp # или CMAKE_SOURCE_DIR
        )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(tutorial_VERSION_MAJOR "1")
set(tutorial_VERSION_MINOR "2")
set(tutorial_VERSION_PATCH "66")

# Данная процедура подхватит значения переменныз из set
# tutorial_VERSION_MAJOR, tutorial_VERSION_MINOR, tutorial_VERSION_PATCH
# и заменит значениями закглушки @tutorial_VERSION_MAJOR, @tutorial_VERSION_MINOR
# @tutorial_VERSION_PATCH input файле .in, результат будет сохранен в
# в output файл десь это TutorialConfig.h
configure_file( ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h.in
                ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h)

add_executable(Step1_project ${SOURCES})

target_include_directories(Step1_project
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h.in
        )


# Еще важная заметка
# CMake по сути конвертер из скриптов в MakeFile и есть разные способы как сгенерировать
# этот MakeFile, CLion о умолчанию использует Ninja в качестве генератора, но
# при вызове cmake из командной строки используется "Unix Make Generators"
# Поэтому, чтобы не нарушать симметрию между созадваемым MakeFile от Clion
# и файла, создаваемого руками, я прописываю в Clion "Unix Make Generators" как
# дефолтные генераторы, File -> Settings -> Build -> Cmake -> Unix Make Generators

##################################
# cd build
# cmake ../
# cmake --build .
##################################


# Некоторрые полезные константы
#
# The root source directory
message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
#
# The current source directory if using sub-projects and directories.
message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
#
# The source directory of the current cmake project.
message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
#
#The root binary / build directory. This is the directory where you ran the cmake command.
# У Clion по умолчанию это cmake-build-debug
message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
#
# The build directory you are currently in.
message("CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")
#
# The build directory for the current project.
message("PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")


