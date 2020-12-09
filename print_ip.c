#include<stdio.h>
#include<string.h>
#include "get_Info.c"

#define LINE_MAX_BYTE 150
#define IP_LENGTH 16
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
    struct IP_info oldfile_Lines[MAX_LINE];     //创建一个结构体变量，用于记录从 temp_receive_line 数组传递过来的旧文件数据
    struct IP_info newfile_Lines[MAX_LINE];     //创建一个结构体变量，用于记录从 temp_receive_line 数组传递过来的新文件数据
    char temp_receive_line[MAX_LINE][LINE_MAX_BYTE]={0};   //创建一个临时数组，用于接收文件流的数据
    FILE * readfile_fp;                     //创建一个指针，用于读取文件
    FILE * writefile_fp;                     //创建一个指针，用于写入文件
    char * ip_ptr;                 //创建一个指针，用于将读取的IP写入结构体成员变量 oldfile_Lines[MAX_LINE].ip
    char * date_ptr;
    char * hittimes_ptr;
    int count=0, oldfile_lines=0, newfile_lines=0;
 
    //读取旧文件的IP，日期，命中数
    //打开文件
    readfile_fp = fopen("old.txt", "r");
    if(readfile_fp == NULL)
    {
        perror("打开文件时发生错误");
	    return(-1);
    }

    while ( (count < MAX_LINE) && (fgets(temp_receive_line[count], LINE_MAX_BYTE, readfile_fp ) != NULL) )
    {
    
        //提取IP
        ip_ptr = oldfile_Lines[count].Ip;      
        get_IP(temp_receive_line[count], ip_ptr); //调用 get_IP.c 中的 get_IP 函数，将读取的IP写入结构体成员变量
    
        //提取日期
        date_ptr = oldfile_Lines[count].Date;
        get_date(temp_receive_line[count], date_ptr, DATE_LENGTH);
    
        //提取命中数
        hittimes_ptr = oldfile_Lines[count].HitTimes;
        get_hitTimes(temp_receive_line[count], hittimes_ptr, HITTIMES_LENGTH);

	count++;
    }

    fclose(readfile_fp);
    oldfile_lines = count;

    //读取新文件的IP，日期，命中数
    count=0;

    //打开文件
    readfile_fp = fopen("new.txt", "r");
    if(readfile_fp == NULL)
    {
        perror("打开文件时发生错误");
	    return(-1);
    }

    while ( (count < MAX_LINE) && (fgets(temp_receive_line[count], LINE_MAX_BYTE, readfile_fp ) != NULL) )
    {
    
        //提取IP
        ip_ptr = newfile_Lines[count].Ip;      
        get_IP(temp_receive_line[count], ip_ptr); //调用 get_IP.c 中的 get_IP 函数，将读取的IP写入结构体成员变量
    
        //提取日期
        date_ptr = newfile_Lines[count].Date;
        get_date(temp_receive_line[count], date_ptr, DATE_LENGTH);
    
        //提取命中数
        hittimes_ptr = newfile_Lines[count].HitTimes;
        get_hitTimes(temp_receive_line[count], hittimes_ptr, HITTIMES_LENGTH);

	count++;
    }

    fclose(readfile_fp);
    newfile_lines = count;

    //暴力比较法，循环提取旧文件的一行，与新文件逐行比较，如果IP相同，写入文件 /tmp/final.txt。
    int count_oldfile=0, count_newfile=0;
    struct IP_info * old_ptr;
    struct IP_info * new_ptr;
    old_ptr = &oldfile_Lines[0];
    new_ptr = &newfile_Lines[0];

    while ( (count_oldfile < oldfile_lines) && (oldfile_Lines[count_oldfile].Ip != NULL) )
    {
        while ( (count_newfile < newfile_lines) && (newfile_Lines[count_newfile].Ip != NULL) )
	{
	    if ( (strcmp(old_ptr->Ip, new_ptr->Ip) == 0) && (strcmp(old_ptr->HitTimes, new_ptr->HitTimes) == 0) )
	    {
                writefile_fp = fopen("/tmp/final.txt", "a+");
		fprintf(writefile_fp, new_ptr->Ip);
		//fprintf(writefile_fp," ");
		//fprintf(writefile_fp,old_ptr->HitTimes);
		fprintf(writefile_fp,"\n");
		fclose(writefile_fp);
		break;
	    }
	    else
	    {
	        count_newfile++;
	        new_ptr++;
	    }
	}
	count_newfile=0;
	new_ptr = &newfile_Lines[0];
	count_oldfile++;
	old_ptr++;
    }
}
