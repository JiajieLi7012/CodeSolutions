/*
 @Date    : 2018-04-16 19:45:36
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�ļ��Ķ�д����
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp1, *fp2;
    int ch;

    if ((fp1 = fopen("Hello.txt", "r")) == NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    if ((fp2 = fopen("fishc.txt", "w")) == NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
