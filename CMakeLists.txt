cmake_minimum_required(VERSION 3.7.2)

project(selyan_string)

add_library(selyan.string src/string.cpp)
target_include_directories(selyan.string
        PUBLIC
        include
        )

add_executable(test.string test/test.string.cpp)
target_link_libraries(test.string
        PRIVATE
        selyan.string
        )