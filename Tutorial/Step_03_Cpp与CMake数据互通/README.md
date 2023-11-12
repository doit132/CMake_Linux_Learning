# 介绍

## message 函数

message 函数可以在终端中输出信息, 当 `cmake ..` 的时候, message 输出的信息就会显示在终端上

## PROJECT_BINARY_DIR 内置变量

这个变量代表我们的构建目录, 也就是最终生成目标文件所要存放的目录

## <PROJECT_NAME>_VERSION_MAJOR 和 <PROJECT_NAME>_VERSION_MINOR 内置变量

- <PROJECT_NAME> 是 project 命令指示的名称
- <PROJECT_NAME>_VERSION_MAJOR 表示版本号的第一个数字, 如 1.0 版本号, 这个变量就表示 1
- <PROJECT_NAME>_VERSION_MINOR 表示版本号的第二个数字, 如 1.0 版本号, 这个变量就表示 0

## configure_file 函数

- configure_file(TutorialConfig.h.in TutorialConfig.h) 复制 TutorialConfig.h 生成 TutorialConfig.h 文件
- 生成的 TutorialConfig.h 文件会放到 PROJECT_BINARY_DIR 表示的路径中

## target_include_directories 函数

- 添加头文件搜索目录
- target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}") 这里之所以加上双引号是为了防止路径可能出现空格导致出现意想不到的错误
- 可以使用空格隔开或者使用回车写多行
