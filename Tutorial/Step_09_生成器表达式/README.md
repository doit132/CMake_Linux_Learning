# 介绍

生成器表达式作用在 CMake 的第 2 阶段, 生成阶段, 所以没法使用 message 函数来输出调试信息, 需要使用 `add_custom_target(ged COMMAND ${CMAKE_COMMAND} -E echo "$<1:hello>")` 这种方式来输出调试信息

解释: 添加一个目标, 目标名称 ged, 然后配置阶段完成后, 可以执行这个目标 `cmake --build . --target ged`

```c
# TODO 1: 创建一些辅助变量用来确定用的是哪个编译器：
# 创建一个变量 gcc_like_cxx 如果用的是 cxx 并且用的是下列任意一个编译器那么值为 true
# ARMClang, AppleClang, Clang, GNU, LCC
# 创建一个变量 msvc_cxx 如果用的是 CXX 和 MSVC 那么值为 true
# Hint: Use set() and COMPILE_LANG_AND_ID
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# TODO 2: 向 interface 库 tutorial_compiler_flags 中添加警告选项:
# 如果是 gcc_like_cxx, 添加 -Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused
# 如果是 msvc_cxx, 添加 -W3
# Hint: Use target_compile_options()
target_compile_options(tutorial_compiler_flags INTERFACE
    "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
    "$<${msvc_cxx}:-W3>"
)

// 使用生成器表达式可以将条件判断写的很集中, 不用像 if, else 那样做很多次的判断, 像上面就是根据不同的编译器设置不同的编译选项
```
