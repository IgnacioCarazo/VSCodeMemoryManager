cmake_minimum_required(VERSION 3.16)
project(CPP)

set(CMAKE_CXX_STANDARD 14)


#add_executable(Ejecutable main.cpp GarbageCollector.cpp GarbageCollector.h VSPtr.h main.cpp)

add_library(CPP SHARED GarbageCollector.cpp GarbageCollector.h VSPtr.h)

