# TrafficAdvisoryServices（全国交通咨询模拟系统设计）

>1st updated in 2017.06.15, Thursday
1. IDE：codeblocks mingw（没有记录当时具体版本号），GCC/G++ compiler and GDB debugger，Windows 10家庭中文版，64bit
3. FCity.txt和TCity.txt分别记录有对应交通工具的城市
4. Flight.txt和Train.txt分别记录对应交通工具的线路

---

>2nd updated in 2017.08.30, Wednesday
1. 在Windows下使用notepad修改了源代码的编码：UTF-8无[BOM](https://zh.wikipedia.org/wiki/%E4%BD%8D%E5%85%83%E7%B5%84%E9%A0%86%E5%BA%8F%E8%A8%98%E8%99%9F)格式。
2. 代码非跨平台，只能在Windows下编译运行。因为引用了window.h头文件。
3. 代码注释中提到的书或页码是这本书：《数据结构（C语言版）》（严蔚敏 吴伟民编著；清华大学出版社）或《C++语言程序设计（第4版）》（郑莉 董渊编著；清华大学出版社）
4. 执行exe文件时，先进入管理员模式导入要使用的工具和路线信息。设置账号和秘密纯属冗余，均为Administrator（代码中有）。

>3rd updated in 2018.08.23, Thursday
