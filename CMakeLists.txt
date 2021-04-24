cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 11)
set(LIBRARY_NAME cfjord)

project(${LIBRARY_NAME} C)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
  "${PROJECT_SOURCE_DIR}/src/*.c"
)

add_library(${LIBRARY_NAME} STATIC ${all_SRCS})
