cmake_minimum_required(VERSION 3.5)

project(example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(image_painter)

add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME} PRIVATE image_painter)




