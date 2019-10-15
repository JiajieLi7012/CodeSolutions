/*
 @Date    : 2018-04-17 19:46:35
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�ж϶�д�ļ��Ĵ���
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;

    if ((fp = fopen("output.txt", "r")) == NULL)
    {
        fputs("���ļ�ʧ�ܣ�\n", stderr);
        exit(EXIT_FAILURE);
    }

    int ch;
    while (1)
    {
        ch = fgetc(fp);
        if (feof(fp))
        {
            break;
        }
        putchar(ch);
    }

    fputc('c', fp);

    if (ferror(fp))
    {
        fputs("�����ˣ�\n", stderr);
    }

    clearerr(fp);
    if (feof(fp) || ferror(fp))
    {
        printf("�ļ��л��д���\n");
    }

    fclose(fp);
    return 0;
}
