//判断是否是0-9的字符，返回值为0(否)或1(是)
int isNumber (char num)
{
    if (( num == '0') || ( num == '1') || ( num == '2') || ( num == '3')|| ( num == '4')
	    || ( num == '5') || ( num == '6') || ( num == '7') || ( num == '8') || (num == '9'))
        return 1;
    else 
	return 0;
}


//ch数组保存原始IP，需要提取处理；ptr指针指向需要把IP写入的内存。
//返回值为完成IP写入的 ptr 指针
char * get_IP(char * ch, char * ptr)
{
    int i;

    for (i=0;i<20;i++)
    {
        if ( (ch[i] == '.') || isNumber(ch[i]) )
	{
	    *ptr = ch[i];
	    ptr++;
	}
	else
	    continue;
    }

    return ptr;
}

//读取ch数组内的日期并写入ptr指针所指内存
char * get_date(char * ch, char * ptr,int date_length)
{
    int i=0,j=0;

    for ( i = 0 ; i < strlen(ch) - 4 ; i++)
    {
            if ( isNumber(ch[i]) && isNumber(ch[i+1]) && isNumber(ch[i+2])
		  && isNumber(ch[i+3]) && (ch[i+4] == '/') )
	    {
		for ( j = 0 ; j < date_length ; j++ )
		{
	            * (ptr+j) = ch[i+j];
		}
		break;
	    }
	    else
		continue;
    }
}

//读取ch数组内的命中数并写入ptr指针所指内存
char * get_hitTimes(char * ch, char * ptr)
{
    int small_location, large_location;
    int i;
    for (i = 0 ; i < strlen(ch) ; i++ )
    {
        if ( (ch[strlen(ch)-1-i] == ' ') && isNumber(ch[strlen(ch)-1-i-1]) 
	{	
            ; 
	}
	else
	    continue;
    }
}
