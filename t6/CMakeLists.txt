cmake_minimum_required(VERSION 3.16)

#创建工程
PROJECT(HELLO)
#设置cmake模块的目录
SET(CMAKE_MODULE_PATH  "${PROJECT_SOURCE_DIR}/cmake")
#指定源文件目录
ADD_SUBDIRECTORY(src)
# 设置 cmake 模块的目录
# list(APPEND CMAKE_MODULE_PATH "/home/maxliang/code/cmake/t6/cmake")
# 输出 CMAKE_MODULE_PATH 的值
MESSAGE(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")