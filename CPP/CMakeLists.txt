cmake_minimum_required(VERSION 3.16)
project(CPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_SOURCE_DIR)

#add_executable(Ejecutable GarbageCollector.cpp GarbageCollector.h VSPtr.h main.cpp )

add_library(CPP SHARED GarbageCollector.cpp GarbageCollector.h VSPtr.h ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(CPP PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

