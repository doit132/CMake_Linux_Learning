# 介绍

## add_library 函数

添加库 add_library(MathFunctions mysqrt.cxx MathFunctions.h)

## add_subdirectory 函数

添加子文件夹 add_subdirectory(MathFunctions)

## PROJECT_SOURCE_DIR 内置变量

这个变量不受在哪个文件夹下的 CMakeLists.txt 影响, 指代的就是你使用 Project 命令的那个 CMakeLists.txt 文件所在的文件夹路径
