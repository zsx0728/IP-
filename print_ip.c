#include<stdio.h>
#include<string.h>
#include "get_Info.c"

#define LINE_MAX_BYTE 130
#define IP_LENGTH 15
#define DATE_LENGTH 20
#define HITTIMES_LENGTH 6
#define MAX_LINE 2048

//创建结构体，记录攻击ip，生成日期，命中数
struct IP_info
{
    char Ip[IP_LENGTH];
    char Date[DATE_LENGTH];
    char HitTimes[HITTIMES_LENGTH];
};

int main(void)
{   
    struct IP_info Lines[MAX_LINE];     //创建一个结构体变量，用于记录从 temp_receive_line 数组传递过来的数据
    char temp_receive_line[MAX_LINE][LINE_MAX_BYTE];   //创建一个临时数组，用于接收文件流的数据
    FILE * readfile_fp;                     //创建一个指针，用于读取文件
    char * ip_ptr;                 //创建一个指针，用于将读取的IP写入结构体成员变量 first_line.ip
    char * date_ptr;
    char * hittimes_ptr;
    int count=0;
 
    //打开文件
    readfile_fp = fopen("file.txt", "r");
    if(readfile_fp == NULL)
    {
        perror("打开文件时发生错误");
	    return(-1);
    }

    while ( (count < MAX_LINE) && (fgets(temp_receive_line[count], LINE_MAX_BYTE, readfile_fp ) != NULL) )
    {
    
        //读取文件的一行，以字符串的形式保存并输出
        //if( fgets(temp_receive_line[count], LINE_MAX_BYTE, readfile_fp ) != NULL )
        //{
    	/* 向标准输出 stdout 写入内容 */
            puts(temp_receive_line[count]);
        //}
    
    
        //提取IP
        ip_ptr = Lines[count].Ip;      
        get_IP(temp_receive_line[count], ip_ptr); //调用 get_IP.c 中的 get_IP 函数，将读取的IP写入结构体成员变量
        puts(Lines[count].Ip);
    
        //提取日期
        date_ptr = Lines[count].Date;
        get_date(temp_receive_line[count], date_ptr, DATE_LENGTH);
        puts(Lines[count].Date); 
    
        //提取命中数
        hittimes_ptr = Lines[count].HitTimes;
        get_hitTimes(temp_receive_line[count], hittimes_ptr, HITTIMES_LENGTH);
        puts(Lines[count].HitTimes); 

	count++;
    }

    fclose(readfile_fp);
}
