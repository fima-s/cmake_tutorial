cmake_minimum_required(VERSION 3.1)

# TODO 14: Remove mysqrt.cxx from the list of sources

# TODO 1: Add a library called MathFunctions with sources MathFunctions.cxx
# and mysqrt.cxx
# Hint: You will need the add_library command

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