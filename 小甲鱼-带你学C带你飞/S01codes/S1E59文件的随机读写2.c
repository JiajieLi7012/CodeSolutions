/*
 @Date    : 2018-04-16 21:09:29
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�ļ��������д2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

struct Stu
{
    char name[24];
    int num;
    float score;
} stu[N], sb;

int main(int argc, char const *argv[])
{
    FILE *fp;

    if ((fp = fopen("source.txt", "w")) == NULL)
    {
        printf("�ļ���ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    printf("�뿪ʼ¼��ɼ������� ѧ�� �ɼ���\n");
    for (unsigned i = 0; i < N; ++i)
    {
        scanf("%s %d %f", stu[i].name, &stu[i].num, &stu[i].score);
    }

    fwrite(stu, sizeof(struct Stu), N, fp);
    fclose(fp);

    if ((fp = fopen("source.txt", "rb")) == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp, sizeof(struct Stu), SEEK_SET);

    fread(&sb, sizeof(struct Stu), 1, fp);
    printf("%s(%d)�ĳɼ��ǣ�%.2f\n", sb.name, sb.num, sb.score);

    fclose(fp);
    return 0;
}
