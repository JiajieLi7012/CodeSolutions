/*
 @Date    : 2018-04-17 20:08:57
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
io��������
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buff[1024];

    memset(buff, '\0', sizeof(buff));

    // setvbuf(stdout, buff, _IOFBF, 1024);
    setvbuf(stdout, buff, _IONBF, 1024);

    fprintf(stdout, "Welcome to bbs.fishc.com\n");

    fflush(stdout);

    fprintf(stdout, "���������ַ���Ż���ʾ�����ַ���\n");

    getchar();

    return 0;
}
