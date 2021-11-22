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


add_executable(workflow_factory main.cpp  Source/Blocks/WriteFile.cpp Source/Blocks/WriteFile.h Source/Blocks/ReadFile.cpp Source/Blocks/ReadFile.h Source/Blocks/Grep.cpp Source/Blocks/Grep.h Source/Blocks/Dump.cpp Source/Blocks/Dump.h Source/Blocks/Sort.cpp Source/Blocks/Sort.h Source/Blocks/Replace.cpp Source/Blocks/Replace.h Source/Blocks/Count.cpp Source/Blocks/Count.h Source/Blocks/IWorker.cpp Source/Blocks/IWorker.h Source/ConfigReader.cpp Source/ConfigReader.h Source/WorkflowExecutor.cpp Source/WorkflowExecutor.h Source/Blocks/Factory.cpp Source/Blocks/Factory.h)
add_executable(CMakeTest Workflowtest.cpp)

target_link_libraries(CMakeTest gtest_main)