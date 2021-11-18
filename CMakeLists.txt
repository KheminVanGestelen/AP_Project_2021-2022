cmake_minimum_required(VERSION 3.12)
project(AP-Project-2021-2022)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP-Project-2021-2021 main.cpp)

include_directories(c:/SFML/include)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
