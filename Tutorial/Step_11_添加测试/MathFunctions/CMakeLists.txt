# 添加一个叫做 MathFunctions 的库
# Hint: You will need the add_library command
# MathFunctions.h 放不放都可以
add_library(MathFunctions mysqrt.cxx MathFunctions.h)

# 将头文件以接口的方式包含
# Hint: 用 target_include_directories 和 INTERFACE
# PUBLIC 本目标需要用, 依赖这个目标的其他目标也需要用
# INTERFACE 本目标不需要, 依赖本目标的其他目标需要
# PRIVATE 本目标需要, 依赖这个目标的其他目标不需要
target_include_directories(MathFunctions INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

# 链接 tutorial_compiler_flags
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

# TODO 1: 创建一个变量 installable_libs 存放
# 需要安装的库名称 (e.g. MathFunctions and tutorial_compiler_flags)
# 然后安装可安装的库文件到 lib 目录下
# Hint: Use the TARGETS and DESTINATION parameters
set(installable_libs MathFunctions tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)

# TODO 2: 把库文件对应的头文件安装到 include 目录下
# Hint: Use the FILES and DESTINATION parameters
install(FILES MathFunctions.h DESTINATION include)
