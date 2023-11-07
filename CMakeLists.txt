cmake_minimum_required(VERSION 3.15)

project(TestProject
    VERSION 0.0.1
    DESCRIPTION "A test project"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(TestProject src/main.cpp)



