cmake_minimum_required (VERSION 3.5)

project (demo)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set (SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.c)

# find testFunc.h
include_directories (${PROJECT_SOURCE_DIR}/testFunc/inc)

# find_library: 在指定目录下查找指定库，并把库的绝对路径存放到变量里，其第一个参数是变量名称，第二个参数是库名称，第三个参数是 HINTS，第 4 个参数是路径，其它用法可以参考 cmake 文档
# 使用 find_library 的好处是在执行 cmake … 时就会去查找库是否存在，这样可以提前发现错误，不用等到链接时
find_library(TESTFUNC_LIB testFunc HINTS ${PROJECT_SOURCE_DIR}/testFunc/lib)

add_executable (main ${SRC_LIST})

#  target_link_libraries: 把目标文件与库文件进行链接
target_link_libraries (main ${TESTFUNC_LIB})
