# undergraduate-experiment

## 说明
1. 2014级本科生课程实验代码备份，仅作为备份。相信几年过去了，学校的课程实验内容应该改变了，学弟学妹们就别想着参考这个repo了。
2. 部分课程代码之前是单独成一个repo的，但综合一些因素，如今合并到同一个repo了，下面有目录检索。
3. 如无特殊说明，所则有代码的环境都是如下：
    + IDE：codeblocks mingw（没有记录当时具体版本号）
    + GCC/G++ compiler and GDB debugger
    + Windows 10家庭中文版，64bit
4. 有删改版的实验报告pdf，用于代替说明文档（就是有点啰嗦）
5. 理论上来说代码跨平台（只要编译器一致）

## 使用
1. 为了方便维护，每门课程的实验单独开了一个分支，有效地避免上传混乱，以后修改时切换对应分支修改后再pull request即可。
2. 同时也方便使用者下载单一某门课程的代码（切换到对应分支，download Zip即为最新版），就不需要为了看部分而下整个repo。
3. **所以下面的课程目录检索只适用于[master](https://github.com/LittleSec/undergraduate-experiment/tree/master)分支**
4. 嗯，这个有点蛋疼，查看在master分支，单独下载在其他分支，当然也可以在某分支单独查看。

## [课程（目录检索）](https://github.com/LittleSec/undergraduate-experiment/tree/master)
1. [C](https://github.com/LittleSec/undergraduate-experiment/tree/master/C2014)
2. [C++](https://github.com/LittleSec/undergraduate-experiment/tree/master/C++2015)
    + [21点游戏/c++/oop](https://github.com/LittleSec/undergraduate-experiment/tree/master/C++2015/Game21Point)
3. [AssemblyLanguage汇编语言](https://github.com/LittleSec/undergraduate-experiment/tree/master/AssemblyLanguage)
4. [CompilerPrinciple编译原理](https://github.com/LittleSec/undergraduate-experiment/tree/master/CompilerPrinciple)
5. [正则表达式/VC6.0](https://github.com/LittleSec/undergraduate-experiment/tree/master/VC6.0GretaRegEx)
6. [网页爬取/python/CCAMLR](https://github.com/LittleSec/undergraduate-experiment/tree/master/SpiderCCAMLR)
7. [html/css](https://github.com/LittleSec/undergraduate-experiment/tree/master/html,css学习)，自学，用html画了几个图而已
8. [DataStructure数据结构](https://github.com/LittleSec/undergraduate-experiment/tree/master/DataStructure)
    + [多项式运算](https://github.com/LittleSec/undergraduate-experiment/tree/master/多项式乘法问题)
    + [迷宫问题](https://github.com/LittleSec/undergraduate-experiment/tree/master/迷宫的求解)-回溯法
    + [Huffman哈夫曼编码](https://github.com/LittleSec/undergraduate-experiment/tree/master/Huffman树及Huffman编码的算法实现)
    + shortest path最短路径问题
        + [校园导游咨询](https://github.com/LittleSec/undergraduate-experiment/tree/master/校园导游咨询)-邻接矩阵图-Dijkstra算法
        + [全国交通咨询模拟系统/cpp](https://github.com/LittleSec/undergraduate-experiment/tree/master/DataStructure/TrafficAdvisoryServices)-邻接表-Floyd算法

## About```toUTF8.py```
1. 由于当时实验的时候使用win下的codeblocks，默认gbk编码，为了现在连微软自家出的vscode也默认使用utf8读写了，因此这个py脚本用于转换文本文件的编码。
2. 脚本会跳过utf-8和ascii两种编码的文本文件，对其他文本文件进行转换。
3. 修改extList能指定需要转换的文本文件类型，默认有'c', 'h', 'cpp', 'p', 'l', 'asm', 'html', 'css', 'py'(**不区分大小写**)
4. 使用：```python toUTF8.py [dir]```，必须指定（有且仅有一个）目录，程序会递归遍历整个目录找出符合的文件进行转换。
5. 需要安装chardet库，```pip install chardet```
6. 已知bug：
    + 若符合转换条件的文本文件里面为空，程序会报错并停止。
7. 其实(这个链接)更好[https://blog.csdn.net/huang_0430/article/details/72638269]，gg!!!