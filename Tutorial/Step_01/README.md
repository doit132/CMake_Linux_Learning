# 介绍

- 在 build 文件夹执行 `cmake --help`, 然后往下拉,找到 The following generators are available on this platform 行, 有 * 号的就是 cmake 默认生成的构建文件
- 如果你在 windows 上使用 `cmake --help` 你会发现, * 指向的是 visual studio(前提是安装了 visual studio)
- 可以使用 `cmake -G "MinGW Makefiles"` 指定生成的构建文件是 MinGW 的 Makefiles (主要是看 `cmake --help` 显示的名称)
- 如果你生成的是 visual studio 的 sln 构建文件, 那么也可以通过 `cmake --build .` 来生成最终目标文件, 这是一种默认的构建目标文件的方式, 不管生成的是什么构建文件, 都可以使用这个命令来生成最终的目标文件
- 如果我想默认生成 MinGW Makefiles 的构建文件, 那么可以将 CMAKE_GENERATOR 环境变量设置成 MinGW Makefiles
