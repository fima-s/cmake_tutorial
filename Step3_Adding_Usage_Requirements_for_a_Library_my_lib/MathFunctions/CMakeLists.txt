cmake_minimum_required(VERSION 3.15)

#-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
set(CMAKE_VERBOSE_MAKEFILE ON)

project(Matf)
add_library(MathFunctions STATIC )

# ВОт зедсь вот мы добавляем интерфейсную библиотеку и фичами
# из за того, что бибилотека интерфейсная то как эти фичи прокидываются
# во все таргеты куда это будет включено
# по моему мнению это не наглядно и лучше использовать старый функционал с сетом
# так это странно выклдядит в вербозном make -> -Dcxx_std_17
# понятно, что это, но ты к такому не привык :)
add_library(tutorial_compiler_flags INTERFACE)
#target_compile_definitions(tutorial_compiler_flags INTERFACE cxx_std_17)

target_sources(
        MathFunctions
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/MathFunctions.cpp
)

target_include_directories( MathFunctions PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(MathFunctions PRIVATE tutorial_compiler_flags)


if(USE_MYMATH)
    add_library(SqrtLibrary STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/mysqrt.cpp)
    message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
    target_include_directories( SqrtLibrary PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
    message("WITH USE_MYMATH=ON")
    # Прокидывание опции, должно быть после add_library или add_executable()
    target_compile_definitions(MathFunctions PRIVATE USE_MYMATH)
    target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
endif()

