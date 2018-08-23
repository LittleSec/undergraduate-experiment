# Game21Point（21点游戏）

>1st updated in 2017.06.15, Thursday

1. IDE：codeblocks mingw（没有记录当时具体版本号），GCC/G++ compiler and GDB debugger，Windows 8.1/7，64bit/32bit
2. 亲测最新版codeblocks 16.01 mingw，Windows 10家庭中文版正常运行。
6. 理论上，不使用面向对象方法会更简单，但课程目的是体会面向对象，因此使用面向对象方法。

----

>2nd update in 2017.08.30, Wednesday

1. 在macOS 10.12.5, Xcode 8.3上备份（拷贝）源代码，因此所上传的源代码的编辑时间并非原始时间。解决了常规跨平台编辑器中文注释乱码问题。
2. 尝试在macOS 10.12.5, Xcode 8.3上编译运行。编译通过，能正常运行，但是结果不正常。
3. 表现在：**`cout`若没有`endl`则无法按预期输出**。系该环境和IDE对C++的兼容问题（bug），并非代码错误。具体原因和缓冲区有关。搜索关键词`Xcode`, `cout`, `C++中输入输出缓冲区的刷新`etc.
4. 该问题网上提供了几种解决方法，如在`cout`后加`ends`或`flush`或改用`printf`，但均不行（`printf`若没有`\n`也是没用。）
5. bootcamp双系统Windows 10 Enterprise 64bit 下直接运行可执行文件中遇到的问题：花色符号无法显示。原因：对ASCII码特殊符号输出的兼容问题。
6. 综上，只给出源代码、实验报告、`.exe(debugger模式)`，编译请结合自己的开发环境。

>3rd update in 2018.08.23, Thursday
