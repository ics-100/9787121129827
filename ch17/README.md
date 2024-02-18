## 第 17 章 x86汇编程序基础

> Latest: Thu Dec  3 17:44:08 CST 2020

**参考资料**

* [深入理解程序设计-使用Linux汇编语言](../../9787115337887)
* [计算机那些事(4)——ELF文件结构](http://chuquan.me/2018/05/21/elf-introduce/)
* [在 Linux 上分析二进制文件的 10 种方法](https://linux.cn/article-12187-1.html)
* [ELF格式文件详细分析](https://blog.csdn.net/xuehuafeiwu123/article/details/72963229)

### 17.5 ELF文件

**17.5.1 目标文件**

```bash
readelf -a max.o
hexdump -C max.o
```

1 - `.shstrtab`: 段保存着各 `Section` 的名字

```bash
readelf -a max.o |grep .shstrtab
# [ 5] .shstrtab         STRTAB          00000000 000150 000030 00      0   0  1

# 30 -> 48
hexdump -C -s 0x150 -n 48  max.o
```

2 - `.strtab` 保存着程序中用到的符号名字，每个名字都是以 `Null` 结尾的字符串

```
readelf -a max.o |grep .strtab
# [ 7] .strtab           STRTAB          00000000 000118 000028 00      0   0  1

# 28 -> 40
hexdump -C -s 0x118 -n 40  max.o
```

3 - `.rel.text` 告诉连接器指令中有哪些地方需要做重定位

4 - `.symtab` 是符号表

* `Ndx` 列是每个符号所在的 `Section` 编号
* `Value` 列是每个符号所代表的地址，在目标文件中，符号地址都是相对于该符号所在 `Section` 的相对地址
* `Bind` 这一列可以看出符号是 `GLOBAL`/ `LOCAL` 


**17.5.2可执行文件**

```bash
readelf -a main
```

* `Entry point address`
* `Text Segment` / `Data Segment`
* 为了简化链接器和加载器的实现，还规定每个 `Segment` 在文件的页面中偏移多少加载到内存页面页要偏移多少
* 相对跳转 / 绝对跳转


**参考资料**

* [https://tool.oschina.net/hexconvert/](https://tool.oschina.net/hexconvert/)
* [Linux GCC常用命令](https://www.cnblogs.com/ggjucheng/archive/2011/12/14/2287738.html)
* [hexdump命令](https://man.linuxde.net/hexdump)