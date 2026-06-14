cmake_minimum_required(VERSION 3.20)
project(game_the_explorer)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC src/*.cpp)

add_executable(app ${SRC})
target_include_directories(app PRIVATE include)