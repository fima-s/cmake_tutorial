cmake_minimum_required(VERSION 3.15)

#-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
set(CMAKE_VERBOSE_MAKEFILE ON)

set(tutorial_VERSION_MAJOR 2)
set(tutorial_VERSION_MINOR 2)
set(tutorial_VERSION_PATCH 66)

## Работает, если прокидываем с самого верхнего уровня
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2 -Werror -Wall")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF) # std=c++11

# Работает, если прокидываем с самого верхнего уровня
option(USE_MYMATH "Use tutorial provided math implementation" ON)

project (Step3_Adding_Usage_Requirements_my_lib
        VERSION ${tutorial_VERSION_MAJOR}.${tutorial_VERSION_MINOR}.${tutorial_VERSION_PATCH})

add_executable(Step3_Adding_Usage_Requirements_my_lib )

target_sources(Step3_Adding_Usage_Requirements_my_lib
              PRIVATE
              ${CMAKE_SOURCE_DIR}/src/tutorial.cpp)

configure_file(
        ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h.in
        ${PROJECT_SOURCE_DIR}/include/TutorialConfig.h)

# Добавляет поддиректорию в проект.
# Поддиректория (в данном случае MathFunctions) указывает директорию
# в которой находится CMakeLists файл и сорцы
# Формально здесь используется относительный путь, можно просто папку писать
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/MathFunctions)

# Здесь мы добавляем библиотеку MathFunctions к нашему проекту
target_link_libraries(
        Step3_Adding_Usage_Requirements_my_lib
        PRIVATE
        MathFunctions
        tutorial_compiler_flags
)

# Определяет директории, которые нужно включить при компиляции указанного таргета
# помещается после add_executable() или add_library()
target_include_directories(
        Step3_Adding_Usage_Requirements_my_lib
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
