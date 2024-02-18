## 第 18 章 汇编与C之间的关系


### 18.1 函数调用

1 - 在编译时加上 `-g` 选项，那么用 `objdump` 反汇编时可以把 `c` 代码和汇编代码穿插起来显示

```bash
gcc main.c -g
objdump -dS a.out
```

2 - 要查看编译后的汇编代码，其实还有一种办法是 `gcc -S main.c`


**基本命令**

> * 表示寄存器名时前面要加个`$`
> * `x/12x %esp` 查看内存中从 esp 寄存器开始的 12 个 32 位数

|命令|描述|
---|---
`disassemble` | 反汇编当前函数或者指定的函数
`si`| 一条指令一条指令地单步调试
`step`| 一行代码一行代码地单步调试
`info registers` | 显示所有寄存器的当前值


**栈空间**

* `esp` 寄存器总是指向栈顶，在 `x86` 平台是从这个栈是从高地址向低地址增长的
* 为了安全性，Linux内核为每个新进程指定的栈空间起始地址都是随机的，所以每次运行这个程序得到的地址都不一样，单通常都是 `0xbf??????` 这样的一个地址

**Calling Convention**

* [x86 calling conventions](https://en.wikipedia.org/wiki/X86_calling_conventions)

### 18.2 main函数、启动历程和退出状态

汇编代码 / 生成目标文件  / 生成可执行文件

|选项|作用|
----|-----
`-S`| 生成汇编代码
`-c` | 生成目标文件
`-E`| 预处理
`-o` | 给输出文件重新命名
`-v` | 详细输出


**查看符号表**

```bash
nm /usr/lib/i386-linux-gnu/crt1.o
```


> * 大写字母是全局符号，小写字母是局部符号，具体每种类型的含义参考 nm(1)
> * `U, Undefined` / `T, Text`

```bash
objdump -d /usr/lib/i386-linux-gnu/crt1.o
```

> C程序的入口点其实是 `ctr1.o` 提供的 `_start`,  它首先做一些初始化工作(启动例程, Startup Routine), 然后调用我们写的 main 函数。

```bash
gcc -c main.c
gcc main.o -o main
objdump -d main
```

> * `符号解析`: 一个目标文件中引用了某个符号，链接器在另一个目标文件中找到这个符号的定义并明确它的地址

```
nm /usr/lib/i386-linux-gnu/crt1.o | grep __libc_start_main
```
> * `_libc_startr_main` 这个符号在共享库 `libc` 中定义
> * 用 `-lc` 选项指定了共享库 `libc`
> * 用 `-dynamic-linker=/lib/ld-linux.so.2` 制定了动态链接器

结束

* `stdlib.h` -> `exit`
* `unistd.h` -> `_exit`


### 18.3 变量的存储布局

* 操作系统的内容管理和编译器的语义检查
* 全局符号 / 局部符号(static)：只能在某一个目标文件中定义和使用


**标识符链接属性**

> 编译单元：经过预处理之后得到的代码称为一个编译单元

* 外部链接: 不同编译单元声明多次，代表同一个内存地址，编译后在目标文件中全局符号
* 内部链接: 不同编译单元声明多次，代表不同的内存地址， 编译后在目标文件中局部符号
* 无链接属性

**存储类型修饰符**

* static 
* auto
* register
* extern: 用于多次声明
* typedef

**类型限定符号**

* const
* volatile
* restrict

###  18.4 结构体和联合体

* 起始内存地址对齐
* 合理设计结构体各成员的排序可以节省存储空间



### 18.5 C内联汇编

* `__asm__()`
* 如果要执行多条汇编指令，则应该用\n\t 将各条指令分隔开

完整的内联汇编格式

```c
__asm__(assembler template					// 汇编指令
		: output operands					// 运算结果输出到那些C语言操作数中， 应该是左值表达式
		: input operands						// 从那些C语言操作数中获得输入
		: list of clobbered registers			// 被修改的寄存器列表
		);
```