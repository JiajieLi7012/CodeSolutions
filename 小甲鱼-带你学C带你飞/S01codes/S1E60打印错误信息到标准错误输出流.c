/*
 @Date    : 2018-04-17 19:42:33
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
���ļ��򿪴���ʱ������Ϣ��ӡ����׼���������
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;

    if ((fp = fopen("yagenjiubucunzaidewenjian.txt", "r")) == NULL)
    {
        fputs("���ļ�ʧ�ܣ�\n", stderr);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return 0;
}
