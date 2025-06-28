cmake_minimum_required(VERSION 3.15)
project(task_1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES
    task.cpp
	main.cpp
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/students.txt
    ${CMAKE_BINARY_DIR}/bin/students.txt
    COPYONLY
)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE "${DATA_DIR}")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)