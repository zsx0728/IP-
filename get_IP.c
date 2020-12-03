char * get_IP(char * ch, char * ptr)
{
    int i;

    for (i=0;i<20;i++)
    {
        if ((ch[i] == '.') || (ch[i] == '0') || (ch[i] == '1') || (ch[i] == '2') || (ch[i] == '3')|| (ch[i] == '4')
	    || (ch[i] == '5') || (ch[i] == '6') || (ch[i] == '7') || (ch[i] == '8') || (ch[i] == '9'))
	{
	    *ptr = ch[i];
	    ptr++;
	}
	else
	    continue;
    }

    return ptr;
}
