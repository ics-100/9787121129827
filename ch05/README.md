## 第 5 章 深入理解函数

**学习记录**

* `Wed Jan 13 14:02:52 CST 2021`
* `Tue Jan 12 14:39:23 CST 2021`

> 电子书有缺页： [http://akaedu.github.io/book/ch05s01.html](http://akaedu.github.io/book/ch05s01.html)


### 5.1 return语句

* 函数返回一个值相当于定义一个和返回值类型相同的临时变量并用return后面的表达式来初始化
* 有些代码路径在任何条件下都执行不到，这称为Dead Code

### 5.2 增量式开发

* 把Scaffolding的代码注释掉
* 尽可能复用（Reuse）以前写的代码，避免写重复的代码

### 5.3 递归

* 自己直接或间接调用自己的函数称为递归函数
* 写递归函数时一定要记得写Base Case