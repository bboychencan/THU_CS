# 程序设计基础大作业

从头开始学习计算机，发现不知道的东西真的太多了。我在这里记录一下在做这个大作业过程中遇到的坑和相应的知识点。

## 大小端
读入二进制图像后，发现数据不对，检查了半天发现顺序是颠倒的，然后才知道有大小端这个概念。

程序在读入二进制存储到int型的时候，自动转换了大小端。

## 字节对齐
我拿struct去存储读进来的BMP文件头，大小端问题搞明白后，发现读取的数据还是不对，挣扎了半天，才知道有字节对齐这个概念。
结构体里面为了保证读取效率，并不允许所有的地址都可以作为读取地址，因此设定了一定的字节对齐规则。

解决方法有几种，一种是用pragma去设置一些对齐规则，这个比较麻烦我就没有深入研究了。
另一种是发现这里面头文件的规律，除了bfType是两字节外，其余的数据要不然是4字节，要不然是连续偶数个两字节，所以自然满足了对齐的要求。 于是分开读取bfType，以及剩余结构体信息。

## 二进制文件显示
使用hexdump 或者 sublime hexviewer 去把二进制文件显示为16进制格式，方便阅读

## 逆序对
想不到简单的一道拼图题也还是用到了一些算法，包括逆序对判断问题是否有解，已经求解算法（考虑用Astar）

1. 先要知道N数码是否可解与逆序对个数和N, M大小的关系（具体证明没有深入了解）
2. 求解逆序对的方法，高效的merge sort 方法

## 如何把程序拆分成多个cpp和头文件
头文件里面声明函数和变量
cpp文件include头文件，注意头文件里不要定义函数或变量，不然会造成重复定义
头文件只有在预处理的时候会用到

## 使用makefile
makefile里面常用的宏


# 一些思考

我开始写这个程序的时候，经常会遇到很难的地方，尝试一段时间没有成功就很容易想放弃。 现在走过了前面几个坑之后往下进展的时候
又遇到了新的问题。

当我能够成功读入图片后，我开始思考如何实现游戏的主逻辑。 这里面的算法和数据结构不难，我本能地就想说要不要把图片直接展示命
令行，这样游戏玩起来才直白且酷炫，然后我发现不知道该怎么把图片显示到命令行，然后参考的程序里面也没有实现，马上又陷入了一个
新的坑，感觉无从下手，然后我发现我很快脑子就开始试图去跑神想一些其他的我能够做到的事情，比如去练会吉他，比如看两节学堂的课。
有点想逃避这个难题，，， 经过一段时间鼓起勇气重新面对的时候，发现还是找不到方法，或者说短时间内解决不了，然后又很容易就转移
注意力，，， 周而复始，效率很低。。。然后还会不断地自责，认为自己太蠢，这个都做不到，而且拖了这么长时间，陷入这个死循环出不
来。

我现在发现了这个规律，我以往类似的经历很多，总结一下都是，我过于在一开始开发的时候就想做到完美，想实现完美的功能，但是这些
完美的功能又超出了我的能力范围，一下子又做不出来，结果问题变得很难，不愿意去面对，逃避，逃避回来还是无法解决，周而复始。

我现在尝试一下是否能够破这个局。
1. 写代码一定从最简单的功能开始做起，实现自己先能做的
2. 对于难的东西，一次只先尝试一点点，不要同时把一大堆难题搅进来，比如对指针还不熟悉，二维指针更不熟，文件读取还没搞扎实，如何反分割文件，分割头文件和函数，同时编译多个文件等都不熟悉，又要开始尝试在命令行显示图片，这等于是不断地在给自己面临的问题添加新的未知变量，整个问题的复杂度变得超出大脑能够处理的范围，因此很难走出来。
3. 学会计算机的思维，化繁为简，分而治之，把问题难度控制在自己能掌握的范围先。不要人为地给自己添加难度。
4. 过于追求完美，追求一次性达到满分的这个心态，这个习惯需要改正