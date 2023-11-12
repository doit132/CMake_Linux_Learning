# 介绍

## option 函数

- 用 option 创建一个变量 USE_MYMATH 默认值设为 ON/OFF, True/False

option(USE_MYMATH "Use tutorial provided math implementation" OFF)

## cmakedefine 和 define 的区别

- 对于非 0 值, 它们两个的效果是一样的

1. 对于 0 值, 它们两个的效果是不一样的, cmakedefine 对于 0 值是直接不进行宏定义的
2. 对于布尔值, 为假的时候, cmakedefine 不会定义, define 会正常定义, 为真时两个都会定义
3. 对于未定义的变量, cmakedfine 不会定义, define 会正常定义

```c
// Defien Tutorial_VERSION_MAJOR 和 Tutorial_VERSION_MINOR
# define Tutorial_VERSION_MAJOR 1
# define Tutorial_VERSION_MINOR "0"

// cmakedefine
# define Tutorial_VERSION_MAJOR 1
/*#undef Tutorial_VERSION_MINOR*/
```
