cmake_minimum_required(VERSION 3.28)
#cmake_minimum_required(VERSION 4.4)

project(game_the_explorer CXX)

file(GLOB_RECURSE SRC src/*.cpp)

add_executable(TheExplorer ${SRC})
target_include_directories(TheExplorer PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_compile_features(TheExplorer PRIVATE cxx_std_20)

