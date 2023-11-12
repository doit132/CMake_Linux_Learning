# 设置 CMake 最低版本要求为 3.15, 生成器表达式是从 cmake3.15 引入的
cmake_minimum_required(VERSION 3.15)

# 创建一个名为 Tutorial 的项目, 将版本号设置为 1.0
project(Tutorial VERSION 1.0)

# 创建一个 interface 库 tutorial_compiler_flags, 它不代表一个真实的库, 只是用来设置一些 C++ 的特性
# Hint: use add_library() with the INTERFACE signature
# 添加编译特性 cxx_std_11 到 tutorial_compiler_flags
# Hint: Use target_compile_features()
add_library(tutorial_compiler_flags INTERFACE)
# 如果设置的版本比默认的低, 那么可能不会生效, 如果设置的比默认的高, 那么会生效
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

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

# 用 option 创建一个变量 USE_MYMATH 默认值设为 ON/OFF, True/False
option(USE_MYMATH "Use tutorial provided math implementation" ON)
message(STATUS "USE_MYMATH is ${USE_MYMATH}")

# 为项目添加一个叫做 Tutorial 的可执行文件
# Hint: 一定要指定源文件 tutorial.cxx
add_executable(Tutorial tutorial.cxx)

# 将 list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions") 删除 (注释掉)
# target_link_libraries 向可执行文件中添加链接库
# -lMathFunctions
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    # list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# 用 configure_file 复制 TutorialConfig.h 生成 TutorialConfig.h 文件
configure_file(TutorialConfig.h.in TutorialConfig.h)

# 链接 tutorial_compiler_flags
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

# 把 EXTRA_INCLUDES 从 target_include_directories() 中删除
# Hint: ${PROJECT_SOURCE_DIR} is a path to the project source. AKA This folder!
# target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}" "${EXTRA_INCLUDES}")
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

add_custom_target(ged COMMAND ${CMAKE_COMMAND} -E echo "$<1:hello>")
