cmake_minimum_required(VERSION 3.1)
set(CMAKE_VERBOSE_MAKEFILE ON)

#option(USE_MYMATH "Use tutorial provided math implementation" ON)

project(MathFunctions)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/MathFunctions.cpp)


# Визуальное наблюдение
# Из за того, что в данной бибилиотке мы тренируемся в использовании опции для
# библиотеки, то у нас случай, когда мы используем std::sqrt и тогда мы получается не должны
# компилировать mysqrt.cpp сорцы.
# Есть много способов, один из них добавить в таком виде
#if (USE_MYMATH)
#    set(SOURCES ${SOURCES} ${PROJECT_SOURCE_DIR}/src/mysqrt.cpp)
#    message("SOURCES = ${SOURCES}")
#endif()

# Второй вариант добавить это в виде библиотеки


add_library(MathFunctions STATIC ${SOURCES})

if(USE_MYMATH)
    add_library(SqrtLibrary STATIC ${PROJECT_SOURCE_DIR}/src/mysqrt.cpp)
    message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
    target_include_directories( SqrtLibrary PRIVATE
            ${PROJECT_SOURCE_DIR}/include)
    target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()


if(USE_MYMATH)
    message("WITH USE_MYMATH=ON")
    # Прокидывание опции, должно быть после add_library или add_executable()
    target_compile_definitions(MathFunctions PRIVATE USE_MYMATH)
endif()


target_include_directories( MathFunctions PRIVATE ${PROJECT_SOURCE_DIR}/include)

#PRIVATE служит для того, чтобы указать какие элементы (исходники, библиотеки, цели)
#необходимы для сборки этой цели. Т.е. эта цель зависима от этих элементов,
#но другие цели, которые будут использовать эту цель в качестве зависимости,
#не получат её зависимости транзитивно. Т.е. если цель A зависит от нашей цели
#Target, у которой в качестве приватной зависимости указана цель Dep, то A не
#будет зависеть от Dep, а Target будет использовать Dep при сборке себя.
#
#INTERFACE служит для указания элементов, которые не нужны для сборки этой цели,
#но они должны быть «прокинуты» для любой цели, которая данную цель указывает
#в качестве зависимости. Т.е. если цель A зависит от нашей цели Target, у которой
#в качестве интерфейсной зависимости указана цель Dep, то A будет зависеть от Dep,
#но Target не будет использовать Dep при сборке себя.
#
#PUBLIC аналогичен связке INTERFACE и PRIVATE. Т.е. если цель A зависит от нашей
#цели Target, у которой в качестве публичной зависимости указана цель Dep, то A
#будет зависеть от Dep, а Target будет использовать Dep при сборке себя.
