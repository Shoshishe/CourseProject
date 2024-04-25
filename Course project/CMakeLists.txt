cmake_minimum_required(VERSION 3.27)
project(Course_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

add_executable(Course_project main.cpp
        StartupScreen/MainWindow.cpp
        StartupScreen/MainWindow.h
        GameScreen/GameScreen.cpp
        GameScreen/GameScreen.h
        WaitScreen/WaitScreen.cpp
        WaitScreen/WaitScreen.h
        Host/Host.cpp
        Host/Host.h
        Client/Client.cpp
        Client/Client.h
        Models/Character.cpp
        Models/Character.h)
target_link_libraries(Course_project
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
)

