#include<stdio.h>
#include<string.h>
#include "get_IP.c"

#define MAX 120
#define IP_LENGTH 15
#define DATE_LENGTH 20
#define HITTIMES_LENGTH 6

//创建结构体，记录攻击ip，生成日期，命中数
struct IP_info
{
    char Ip[IP_LENGTH];
    char Date[DATE_LENGTH];
    int HitTimes;
};

int main(void)
{   
    struct IP_info first_line;     //创建一个结构体变量，用于记录从 temp_receive_line 数组传递过来的数据
    char temp_receive_line[MAX];   //创建一个临时数组，用于接收文件流的数据
    FILE * readfile_fp;                     //创建一个指针，用于读取文件
    char * ip_ptr;                 //创建一个指针，用于将读取的IP写入结构体成员变量 first_line.ip
    char * date_ptr;

    //打开文件
    readfile_fp = fopen("file.txt", "r");
    if(readfile_fp == NULL)
    {
        perror("打开文件时发生错误");
	return(-1);
    }

    //读取文件的一行，以字符串的形式保存并输出
    if( fgets(temp_receive_line, MAX, readfile_fp) != NULL )
    {
	/* 向标准输出 stdout 写入内容 */
        puts(temp_receive_line);
    }

    fclose(readfile_fp);

    //提取IP
    ip_ptr = first_line.Ip;      
    get_IP(temp_receive_line, ip_ptr); //调用 get_IP.c 中的 get_IP 函数，将读取的IP写入结构体成员变量
    puts(first_line.Ip);

    //提取日期
    date_ptr = first_line.Date;
    get_date(temp_receive_line, date_ptr, DATE_LENGTH);
    puts(first_line.Date); 
}
