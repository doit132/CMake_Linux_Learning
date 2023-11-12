# 设置 CMake 最低版本要求为 3.10
cmake_minimum_required(VERSION 3.10)

# 创建一个名为 Tutorial 的项目, 将版本号设置为 1.0
project(Tutorial VERSION 1.0)

# 设置变量 CMAKE_CXX_STANDARD 为 11
# CMAKE_CXX_STANDARD_REQUIRED 为 True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 用 configure_file 复制 TutorialConfig.h 生成 TutorialConfig.h 文件
configure_file(TutorialConfig.h.in TutorialConfig.h)

# TODO 2: 用 add_subdirectory()把 MathFunctions 添加到项目中
add_subdirectory(MathFunctions)

# 为项目添加一个叫做 Tutorial 的可执行文件
# Hint: 一定要指定源文件 tutorial.cxx
add_executable(Tutorial tutorial.cxx)

# TODO 3：用 target_link_libraries 向可执行文件中添加链接库
# -lMathFunctions
target_link_libraries(Tutorial PUBLIC MathFunctions)

# TODO 4: 把 MathFunctions 目添加到 Tutorial 的 target_include_directories()中
# Hint: ${PROJECT_SOURCE_DIR} is a path to the project source. AKA This folder!
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/MathFunctions")

