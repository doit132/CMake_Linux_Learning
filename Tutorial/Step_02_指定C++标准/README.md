# 介绍

## CMAKE_CXX_STANDARD 内置变量

- std::stod 是在 C++ 11 的时候引入的, 如果设置的 C++ 标准低于这个标准, 那么 cmake 构建后, make 的时候会报错, 比如设置为 C++98 标准, set(CMAKE_CXX_STANDARD 98)
- 在 C++ 中可以通过输出 __cplusplus 查看当前编译器所用的标准

| __cplusplus 的值 | 对应的C++标准 |
| ---------------- | ------------- |
| 199711           | C++98         |
| 201103           | C++11         |
| 201402           | C++14         |
| 201703           | C++17         |
| 202002           | C++20         |
|                  | C++23         |

## CMAKE_CXX_STANDARD_REQUIRED 内置变量

- set(CMAKE_CXX_STANDARD_REQUIRED True)
  - True: 如果我们设置的标准, 编译器不支持, 那么会报错
  - False: 如果我们设置的标准, 编译器不支持, 那么会使用上一个版本的标准
