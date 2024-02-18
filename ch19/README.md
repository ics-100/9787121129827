## 第19章 链接详解

### 19.1 多目标文件的链接

* 链接脚本(LInker Script)
* `ld`  / `-T` `-verbose`


* ENTRY(_start) 指明整个程序的入口点是 \_start


### 19.2 定义和声明

**19.2.1 extern 和 static 关键字**

* 用 extern 关键字修饰的函数具有 External Linkpage
* 用 static 关键字修饰的函数具有 Internal Linkpage

**19.2.2 头文件**

* 对于用角括号包含的头文件，gcc首先查找 `-I` 选项指定的目录，然后查找系统的头文件目录
* 用引号包含的头文件，gcc首先查找包含头文件的.c文件所在的目录，然后查找-I选项指定的目录，然后查找系统的头文件目录
* 预处理指示中可以使用相对路径
* `-I` 选项可以指定相对路径也可以指定绝对路径，如果指定相对路径，它是相对于 `gcc` 进行的当前工作目录的路径

Header Guard

* `#ifndef` ~ `#endif`

### 19.3 静态库

* 库文件名都是以 `lib` 开头的，静态库以 `.a` 作为后缀，表示Archive

```bash
ar # 静态库打包
r 将后面的目标文件添加到文件包
s 为静态库创建索引

ranlib命令也可以为静态库创建索引
```

**编译选项**

* `-L` 选项告诉编译器去哪里找需要的库文件
* 所以编译器是优先考虑共享库的，如果希望编译器只链接静态库，可以指定 `-static` 选项。

```bash
gcc -print-search-dirs
```

### 19.4 共享库

* PIC 位置无关代码(Position Independent Code)
* `ldd`: 查看可执行文件依赖那些共享库

查看可执行文件依赖于哪些共享库

`ldd main`

**动态链接器**

* `LD_LIBRARY_PATH`
* `/etc/ld.so.cache` - `/etc/ld.so.conf`
* `ldconfig -v`

**19.4.3 共享库的命名惯例**

* 每个共享库有三个文件名：real name、soname和linker name
* 真正的库文件（而不是符号链接）的名字是real name，包含完整的共享库版本号
* soname是一个符号链接的名字，只包含共享库的主版本号，主版本号一致即可保证库函数的接口一致，因此应用程序的.dynamic段只记录共享库的soname，只要soname一致，这个共享库就可以用
* linker name仅在编译链接时使用，gcc的-L选项应该指定linker name所在的目录。有的linker name是库文件的一个符号链接，有的linker name是一段链接脚本


**19.5 虚拟内存管理**

`cat /proc/<pid>maps`