# 介绍

然后 cd 到 build 目录下输入 cmake … && make 就可以只编译出 main1，如果想编译出 main2，就把 MYDEBUG 设置为 ON，再次输入 cmake … && make 重新编译。

每次想改变 MYDEBUG 时都需要去修改 CMakeLists.txt，有点麻烦，其实可以通过 cmake 的命令行去操作，例如我们想把 MYDEBUG 设置为 OFF，先 cd 到 build 目录，然后输入 cmake … -DMYDEBUG=ON，这样就可以编译出 main1 和 main2 （在 bin 目录下）
