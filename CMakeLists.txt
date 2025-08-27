cmake_minimum_required(VERSION 3.31)

project(
    "Stratadex"
    VERSION "0.0.0"
    LANGUAGES "CXX"
)

# list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.9.1/msvc2022_64/lib/cmake/Qt6")

set(CMAKE_CXX_STANDARD 17)
set(AUTOMOC ON)

# find_package(SFML COMPONENTS graphics window system REQUIRED)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

qt_standard_project_setup()

set(SRCS
    src/main.cpp
    src/main_menu.cpp
    src/quiz.cpp
    src/stratagem.cpp
)

set(EXEC_TARGET "Stratadex")

qt_add_executable(${EXEC_TARGET} ${SRCS})

target_link_libraries(${EXEC_TARGET} PRIVATE 
    Qt6::Widgets
    Qt6::Core    
    Qt6::Gui
)