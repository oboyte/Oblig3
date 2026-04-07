cmake_minimum_required(VERSION 3.16)

project(Oblig3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Oblig3 main.cpp
    rom.h rom.cpp
    building.h
    building.cpp
    data )

include(GNUInstallDirs)
install(TARGETS Oblig3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
