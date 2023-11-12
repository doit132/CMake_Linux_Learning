# TODO 1: 设置 CMake 最低版本要求为 3.10
cmake_minimum_required(VERSION 3.10)

# TODO 2: 创建一个名为 Tutorial 的项目
project(Tutorial)

# TODO 5: 设置变量 CMAKE_CXX_STANDARD 为 11
# CMAKE_CXX_STANDARD_REQUIRED 为 True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO 3:为项目添加一个叫做 Tutorial 的可执行文件
# Hint: 一定要指定源文件 tutorial.cxx
add_executable(Tutorial tutorial.cxx)
