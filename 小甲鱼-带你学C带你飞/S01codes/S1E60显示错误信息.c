/*
 @Date    : 2018-04-17 19:52:36
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
��ʾ����ԭ��
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    FILE *fp;

    // if ((fp = fopen("yagenjiubucunzaidewenjian.txt", "r")) == NULL)
    // {
    //     printf("���ļ�ʧ�ܣ�ԭ���ǣ�%d\n", errno);
            // exit(EXIT_FAILURE);
    // }


    // if ((fp = fopen("yagenjiubucunzaidewenjian.txt", "r")) == NULL)
    // {
    //     perror("���ļ�ʧ�ܣ�ԭ����");
    //     exit(EXIT_FAILURE);
    // }

    if ((fp = fopen("yagenjiubucunzaidewenjian.txt", "r")) == NULL)
    {
        fprintf(stderr, "���ļ�ʧ�ܣ�ԭ���� %s!���ᣡ\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    return 0;
}
