# 设置 CMake 最低版本要求为 3.10
cmake_minimum_required(VERSION 3.10)

# 创建一个名为 Tutorial 的项目, 将版本号设置为 1.0
project(Tutorial VERSION 1.0)

# 设置变量 CMAKE_CXX_STANDARD 为 11
# CMAKE_CXX_STANDARD_REQUIRED 为 True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO 1: 用 option 创建一个变量 USE_MYMATH 默认值设为 ON/OFF, True/False
option(USE_MYMATH "Use tutorial provided math implementation" ON)
message(STATUS "USE_MYMATH is ${USE_MYMATH}")

# 为项目添加一个叫做 Tutorial 的可执行文件
# Hint: 一定要指定源文件 tutorial.cxx
add_executable(Tutorial tutorial.cxx)

# TODO 2：通过 if 判断是否将 MathFunctions 库链接到可执行文件
# target_link_libraries 向可执行文件中添加链接库
# -lMathFunctions
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# 用 configure_file 复制 TutorialConfig.h 生成 TutorialConfig.h 文件
configure_file(TutorialConfig.h.in TutorialConfig.h)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# TODO 3: 把 EXTRA_INCLUDES 添加到 Tutorial 的 target_include_directories() 中
# Hint: ${PROJECT_SOURCE_DIR} is a path to the project source. AKA This folder!
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}" "${EXTRA_INCLUDES}")

