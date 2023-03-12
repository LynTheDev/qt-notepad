cmake_minimum_required(VERSION 3.24)
project(notepad)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_executable(notepad resources/resources.qrc src/main.cpp ui/mainwindow.cpp include/mainwindow.h ui/mainwindow.ui)

target_include_directories(notepad PRIVATE
        include/
        ui/
)

target_link_libraries(notepad PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)