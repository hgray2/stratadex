cmake_minimum_required(VERSION 3.31)

project(
    "Stratadex"
    VERSION "0.0.1"
    LANGUAGES "CXX"
)

set(CMAKE_CXX_STANDARD 17)
set(AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Gui Multimedia Widgets REQUIRED)

qt_standard_project_setup()

set(SRCS
    stratadex.qrc
    src/main.cpp
    src/quiz.cpp
    src/main_menu.cpp
    src/main_window.cpp
    src/stratagem.cpp
    src/stratagem_model.cpp
)

set(EXEC_TARGET "Stratadex")

qt_add_executable(${EXEC_TARGET} WIN32 ${SRCS})

target_include_directories(${EXEC_TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/project_config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/project_config.h
)

target_include_directories(${EXEC_TARGET} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# qt_add_exec links Qt6::Core by default.
target_link_libraries(${EXEC_TARGET} PUBLIC 
    Qt6::Widgets
    Qt6::Gui
    Qt6::Multimedia
)




