cmake_minimum_required(VERSION 3.15)
project(Lab8 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(task_1)
add_subdirectory(task_2)
add_subdirectory(task_3)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} task_1 task_2 task_3)