/*
 @Date    : 2018-04-15 17:31:56
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
ö�ٺ�ʱ���Ӧ��
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    enum Week {SUN, MON, TUE, WED, THU, FRI, SAT};
    enum Week today;

    struct tm *p;
    time_t t;

    time(&t);
    p = localtime(&t);

    today = p->tm_wday;

    switch (today)
    {
        case MON:
        case TUE:
        case WED:
        case THU:
        case FRI:
            printf("������T_T\n");
            break;
        case SAT:
        case SUN:
            printf("�ż٣�^_^\n");
            break;
        default:
            printf("Error\n");
            break;
    }
    return 0;
}
