/*
 @Date    : 2018-04-16 16:30:48
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�򿪺͹ر��ļ�
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    int ch;

    if ((fp = fopen("hello.txt", "r")) == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);

    return 0;
}
