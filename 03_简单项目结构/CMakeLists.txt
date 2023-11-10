cmake_minimum_required (VERSION 2.8)

project (demo)

# 使用 aux_source_directory 把当前目录下的源文件存列表存放到变量 SRC_LIST 里
# aux_source_directory(. SRC_LIST)

# aux_source_directory () 也存在弊端，它会把指定目录下的所有源文件都加进来，可能会加入一些我们不需要的文件，此时我们可以使用 set 命令去新建变量来存放需要的源文件
set(SRC_LIST
    ./main.c
    ./testFunc1.c
    ./testFunc.c)

add_executable(main ${SRC_LIST})
