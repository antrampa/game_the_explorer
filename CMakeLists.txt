cmake_minimum_required(VERSION 3.10)
project(TheExplorer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(app
    src/main.cpp
    src/Animal.cpp
    src/Player.cpp
    src/City.cpp
    src/CityKastoria.cpp
)