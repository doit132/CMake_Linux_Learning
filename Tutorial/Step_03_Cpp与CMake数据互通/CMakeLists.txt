# TODO 1: 设置 CMake 最低版本要求为 3.10
cmake_minimum_required(VERSION 3.10)

# TODO 2: 创建一个名为 Tutorial 的项目, 将版本号设置为 1.0
project(Tutorial VERSION 1.0)

# TODO 5: 设置变量 CMAKE_CXX_STANDARD 为 11
# CMAKE_CXX_STANDARD_REQUIRED 为 True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO 6: 用 configure_file 复制 TutorialConfig.h 生成 TutorialConfig.h 文件
configure_file(TutorialConfig.h.in TutorialConfig.h)

# TODO 3: 为项目添加一个叫做 Tutorial 的可执行文件
# Hint: 一定要指定源文件 tutorial.cxx
add_executable(Tutorial tutorial.cxx)

# TODO 8: 用 target_include_directories 添加头文件搜索目录 ${PROJECT_BINARY_DIR}
# PUBLIC PRIVATE INTERFACE
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

message(STATUS "hello world cmake")

