# 设置 CMake 最低版本要求为 3.10
cmake_minimum_required(VERSION 3.10)

# 创建一个名为 Tutorial 的项目, 将版本号设置为 1.0
project(Tutorial VERSION 1.0)

# TODO 1: 将下面的代码替换为
# 创建一个 interface 库 tutorial_compiler_flags, 它不代表一个真实的库, 只是用来设置一些 C++ 的特性
# Hint: use add_library() with the INTERFACE signature
# 添加编译特性 cxx_std_11 到 tutorial_compiler_flags
# Hint: Use target_compile_features()
add_library(tutorial_compiler_flags INTERFACE)
# 如果设置的版本比默认的低, 那么可能不会生效, 如果设置的比默认的高, 那么会生效
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

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

# TODO 2: 链接 tutorial_compiler_flags
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

# 把 EXTRA_INCLUDES 从 target_include_directories() 中删除
# Hint: ${PROJECT_SOURCE_DIR} is a path to the project source. AKA This folder!
# target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}" "${EXTRA_INCLUDES}")
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

