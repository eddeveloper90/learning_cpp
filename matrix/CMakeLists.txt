cmake_minimum_required(VERSION 3.15)

SET(TARGET_NAME matrix)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-O2 -std=c++14")

project (${TARGET_NAME})

file(GLOB SOURCES "src/*.cpp")

add_executable(matrix ${SOURCES})

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${TARGET_NAME} PRIVATE include)

#add_library(vector STATIC ${SOURCES}/vector.cpp)
#find_library(VECTOR_LIBRARY vector lib)
#target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${VECTOR_LIBRARY})

#include_directories(include)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)
#target_link_libraries(${PROJECT_NAME}
#        ${CMAKE_CURRENT_SOURCE_DIR}/libs/libitpp.so
#        )