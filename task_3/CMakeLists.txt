cmake_minimum_required(VERSION 3.15)
project(task_3)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES
    task.cpp
	main.cpp
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/image.png
    ${CMAKE_BINARY_DIR}/bin/image.png
    COPYONLY
)

find_package(OpenCV 4 REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS} OpenSSL::SSL OpenSSL::Crypto)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)