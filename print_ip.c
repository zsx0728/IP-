#include<stdio.h>
#include "get_IP.c"

#define MAX 120
#define IP_LENGTH 15
#define DATE_LENGTH 20
#define HITTIMES_LENGTH 5
char * get_IP(char * ch, char * ip_ptr);

struct IP_info
{
    char ip[IP_LENGTH];
    char Date[DATE_LENGTH];
    int HitTimes;
};

int main(void)
{
    struct IP_info first_line;
    char temp_receive_line[MAX];
    FILE * fp;
    char * ip_ptr;

    fp = fopen("file.txt", "r");
    if(fp == NULL)
    {
        perror("打开文件时发生错误");
	return(-1);
    }

    if( fgets(temp_receive_line, MAX, fp) != NULL )
    {
	/* 向标准输出 stdout 写入内容 */
        puts(temp_receive_line);
    }

    fclose(fp);

    ip_ptr = first_line.ip;
    get_IP(temp_receive_line, ip_ptr);
    puts(first_line.ip);

}
