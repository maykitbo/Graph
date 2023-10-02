cmake_minimum_required(VERSION 3.5)

project(example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cc
)


add_subdirectory(image_painter)

add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
        ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE image_painter)

# target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# target_link_libraries(${PROJECT_NAME} PRIVATE image_painter Qt${QT_VERSION_MAJOR}::Widgets)



