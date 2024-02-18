## 第 16 章 计算机体系结构基础

> Latest: Thu Dec  3 14:36:45 CST 2020


### 16.4 MMU

* `Virtual Memory Management` : 虚拟内存管理
* `Memory Management Unit, MMU`: 内存管理单元
* 虚拟地址 (`Virtual Address, VA`)/ 物理地址`(Physical Adress, PA)`
* `MMU` 将 `VA` 映射到 `PA` 是以页(`Page`)为单位的, 32位处理器的页尺寸通常是`4KB`


### 16.5 Memory Hierarchy

* 把存储器分成若干级，称为`Memory Hierarchy`,按照离CPU由近到远的顺序依次是CPU寄存器、Cache、内存、硬盘，越靠近CPU的存储器容量越小但访问速度越快