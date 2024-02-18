## 第 10 章 gdb

> [LLDB](https://lldb.llvm.org/)

**学习记录**

* `Thu Jan 14 14:37:23 CST 2021`
* `Wed Jan 13 18:16:36 CST 2021`
* `Mon Sep 28 21:22:25 CST 2020`


### 10.1 单步执行和跟踪函数调用

> * 在编译时要加上 `-g` 选项，生成的可执行文件才能用gdb进行源码级调试
> * gdb提供了一个很方便的功能，在提示符下直接敲回车表示重复上一条命令

**基本命令1**

|命令|描述|
---|---
`list (或 l)`| 列出源代码，接着上次的位置往下列，每次列10行
`list 行号`| 列出从第几行开始的源代码
`list 函数名`| 列出某个函数的源代码 
`quit (或 q)` | 退出gdb调试环境
`start` | 开始执行程序，停在main函数第一行语句前面等待命令
`next (或n)` | 执行下一行语句
`step(或s)`| 执行下一行语句，如果有函数调用则进入到函数中
`backtrace (或bt)`| 查看各级函数调用及参数
`info(或i) locals`| 查看当前栈帧局部变量的值
`frame(或f) 帧编号` | 选择栈帧
`print（或p）` |  打印表达式的值，通过表达式可以修改变量的值或者调用函数
`finish` | 连续运行到当前函数返回为止，然后听下来等待命令
`set var` | 修改变量的值

### 10.2 断点

> 注意字符型的'2'要减去'0'的ASCII码才能转换成整数值2

**基本命令2**

|命令|描述|
---|---
`display 变量名`| 跟踪查看某个变量，每次停下来都显示它的值
`undisplay 跟踪显示号` | 取消跟踪显示
`break(或b) 行号` | 在某行设置断点
`break 函数名`| 在某个函数的开头设置断点
`break .. if ...`| 设置条件断点
`info(或i) breakpoints`| 查看设置了哪些断点
`delete breakpoints 断点号`| 删除断点
`disable breakpoints 断点号`| 禁用断点
`enable 断点号` | 启用断点
`contineu(或c)`| 从当前位置开始连续运行程序
`run(或r)` | 从头开始连续运行程序

### 10.3 观察点

**x命令打印指定存储单元的内容**

> `x/7bx`

* `7bx` 是打印格式，`b` 表示每个字节一组，`7` 表示打印7组, `x` 表示按16进制格式打印
* 断点是当程序执行到某一代码行时中断
* 观察点是当程序访问某个存储单元时中断

**基本命令3**

|命令|描述|
---|---
`watch` | 设置观察点
`info(或i) watchpoints` | 查看设置了哪些观察点
`x` | 从某个位置开始打印存储单元的内容，全部当成字节来看而不区分那个字节属于那个变量

**10.4段错误**