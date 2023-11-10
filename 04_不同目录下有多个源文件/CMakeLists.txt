cmake_minimum_required (VERSION 2.8)

project (demo)

# include_directories 该命令是用来向工程添加多个指定头文件的搜索路径, 路径之间用空格分隔
include_directories (test_func test_func1)

# 使用 aux_source_directory 把当前目录下的源文件存列表存放到变量 SRC_LIST 里
aux_source_directory (test_func SRC_LIST)
aux_source_directory (test_func1 SRC_LIST1)

add_executable (main main.c ${SRC_LIST} ${SRC_LIST1})
