cmake_minimum_required(VERSION 3.10)
project(SingletonProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(SingletonDemo src/main.cpp)
target_include_directories(SingletonDemo PUBLIC include)