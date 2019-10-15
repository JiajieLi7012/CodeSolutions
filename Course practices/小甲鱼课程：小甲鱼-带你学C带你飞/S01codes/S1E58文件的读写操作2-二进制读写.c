/*
 @Date    : 2018-04-16 20:11:13
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�����ƶ�д�ļ�
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
    int year, month, day;
};

struct Book
{
    char name[40], author[40], publisher[40];
    struct Date date;
};


int main(int argc, char const *argv[])
{
    FILE *fp;
    struct Book *book_for_read, *book_for_write;

    book_for_write = (struct Book *)malloc(sizeof(struct Book));
    book_for_read = (struct Book *)malloc(sizeof(struct Book));

    if (book_for_read == NULL || book_for_write == NULL)
    {
        printf("�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }

    strcpy(book_for_write->name, "������ѧC����ɡ�");
    strcpy(book_for_write->author, "С����");
    strcpy(book_for_write->publisher, "�廪��ѧ������");
    book_for_write->date.year = 2018;
    book_for_write->date.month = 4;
    book_for_write->date.day = 16;


    if ((fp = fopen("text.txt", "w")) == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    fwrite(book_for_write, sizeof(struct Book), 1, fp);
    fclose(fp);

    if ((fp = fopen("text.txt", "r")) == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        exit(EXIT_FAILURE);
    }

    fread(book_for_read, sizeof(struct Book), 1, fp);
    fclose(fp);

    printf("����: %s\n", book_for_read->name);
    printf("����: %s\n", book_for_read->author);
    printf("������: %s\n", book_for_read->publisher);
    printf("����: %d-%d-%d\n", book_for_read->date.year, book_for_read->date.month,
        book_for_read->date.day);


    return 0;
}
