cmake_minimum_required (VERSION 3.5)

project (demo)

set(SRC_LIST ${PROJECT_SOURCE_DIR}/testFunc/testFunc.c)

# add_library: 生成动态库或静态库 (第 1 个参数指定库的名字；第 2 个参数决定是动态还是静态，如果没有就默认静态；第 3 个参数指定生成库的源文件)
add_library (testFunc_shared SHARED ${SRC_LIST})
add_library (testFunc_static STATIC ${SRC_LIST})

# set_target_properties: 设置最终生成的库的名称，还有其它功能，如设置库的版本号等
# LIBRARY_OUTPUT_PATH: 库文件的默认输出路径，这里设置为工程目录下的 lib 目录
# PS：前面使用 set_target_properties 重新定义了库的输出名称, 如果不使用 set_target_properties 也可以, 那么库的名称就是 add_library 里定义的名称, 只是连续 2 次使用 add_library 指定库名称时（第一个参数）, 这个名称不能相同，而 set_target_properties 可以把名称设置为相同, 只是最终生成的库文件后缀不同（一个是.so, 一个是.a）, 这样相对来说会好看点
set_target_properties (testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
set_target_properties (testFunc_static PROPERTIES OUTPUT_NAME "testFunc")

set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
