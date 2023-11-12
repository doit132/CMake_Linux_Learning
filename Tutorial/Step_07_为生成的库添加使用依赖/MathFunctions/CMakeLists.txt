# TODO 4: 添加一个叫做 MathFunctions 的库
# Hint: You will need the add_library command
# MathFunctions.h 放不放都可以
add_library(MathFunctions mysqrt.cxx MathFunctions.h)

# TODO 5: 将头文件以接口的方式包含
# Hint: 用 target_include_directories 和 INTERFACE
# PUBLIC 本目标需要用, 依赖这个目标的其他目标也需要用
# INTERFACE 本目标不需要, 依赖本目标的其他目标需要
# PRIVATE 本目标需要, 依赖这个目标的其他目标不需要
target_include_directories(MathFunctions INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
