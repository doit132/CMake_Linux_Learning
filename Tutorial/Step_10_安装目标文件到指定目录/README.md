# 介绍

```c
# TODO 1: 安装 Tutorial 到 bin 目录 ${CMAKE_INSTALL_PREFIX}
# Hint: Use the TARGETS and DESTINATION parameters
install(TARGETS Tutorial DESTINATION bin)
message(STATUS "Tutorial is installed to ${CMAKE_INSTALL_PREFIX}/bin")

# ${CMAKE_INSTALL_PREFIX} 默认表示的是 cmake 的安装目录, 在 Linux 下是/usr/local/bin
# 可以使用 set 给 CMAKE_INSTALL_PREFIX 重新赋值
# 也可以使用 `cmake --install . --prefix=/home/doit/CMakeList_Linux_Learning/Tutorial/Step_10_安装目标文件到指定目录/install`
```

## CMAKE_INSTALL_PREFIX 内置变量

这个内置变量默认是指 cmake 的安装目录, 可以使用 set 函数来各这个内置变量重新赋值
