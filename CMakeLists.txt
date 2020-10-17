cmake_minimum_required(VERSION 3.5)

project(thread_pool_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_libraries(pthread)

add_executable(thread_pool_example main.cpp
                                    threadpool.cpp
                                    threadpool.h)
