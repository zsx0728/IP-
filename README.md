# 华为防火墙黑名单IP分析工具

## 工具作用：
分析华为防火墙黑名单新旧记录，找出没有新增攻击的IP，将IP及攻击数写入文件/tmp/final.txt。
## 使用方法：
### 1.Linux环境下下载本工具代码
```c
# git clone https://github.com/zsx0728/IP-analysis.git
```
### 2.准备分析文件
&ensp;&ensp;&ensp;&ensp;进入IP-analysis目录，在该目录下准备新旧记录文件，分别命名为old.txt、new.txt。文件内容需要在防火墙上使用 display firewall blacklist item 命令生成，删除表头，只留内容，类似：<br>
 118.244.128.0 /any (src) /any/                               Manual               2020/09/25 09:05:52    Permanent 625               
 106.12.160.6 /any (src) /any/                                Manual               2020/09/21 14:10:31    Permanent 368               
 ...
### 3.编译并执行
```c
# gcc print_ip.c -o print
# ./print
```
### 4.生成 /tmp/final.txt 文件，检查结果。
```c
# ll /tmp/final.txt
-rw-r--r-- 1 root root 17 Dec 10 10:57 /tmp/final.txt
```

## 更新记录：
#20201203 完成读取首行IP的任务；<br>
#20201204 完成读取首行日期的任务；<br>
#20201206 完成读取首行命中数的任务；<br>
#20201207 逐行读取文件并处理；<br>
#20201208 读取新旧文件，通过暴力比较法，找出相同IP并写入文件；<br>
#20201209 修改BUG，提取命中数相同的IP，并写入文件。
