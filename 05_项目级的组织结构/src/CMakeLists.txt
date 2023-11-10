aux_source_directory (. SRC_LIST)

include_directories(../include)

add_executable (main ${SRC_LIST})

# 这里的 set 其实是和前面的一样，只是 EXECUTABLE_OUTPUT_PATH 是个系统自带的预定义变量，其意义如下：
# EXECUTABLE_OUTPUT_PATH ：目标二进制可执行文件的存放位置
# PROJECT_SOURCE_DIR：工程的根目录
# 所以，这里 set 的意思是把存放 elf 文件的位置设置为工程根目录下的 bin 目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
