#include<stdio.h>
#define MAX 16

int main(void)
{
    int ch[MAX];
    FILE * fp;
    int i=0;

    fp = fopen("file.txt", "r");

    for ( i = 0 ;i < MAX; i++)
    {
        ch[i]=fgetc(fp);
        if ( ch[i] != ' ')
        {   
            printf("%c",ch[i]);
        }
        else
            break;
    }

    fclose(fp);
}
