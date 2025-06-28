cmake_minimum_required(VERSION 3.15)
project(task_2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES
    task.cpp
	main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)