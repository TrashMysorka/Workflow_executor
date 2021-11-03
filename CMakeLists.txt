cmake_minimum_required(VERSION 3.17)
project(workflow_factory)

set(CMAKE_CXX_STANDARD 14)

add_executable(workflow_factory main.cpp workflow.h workflow.cpp)