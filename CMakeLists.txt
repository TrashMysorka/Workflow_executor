cmake_minimum_required(VERSION 3.17)
project(hash_table)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


add_executable(workflow_factory main.cpp workflow.h workflow.cpp)
add_executable(CMakeTest Workflowtest.cpp workflow.h workflow.cpp)

target_link_libraries(CMakeTest gtest_main)