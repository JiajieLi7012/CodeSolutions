#include <stdio.h>

int main()
{
    char name[256];
    float h, w;

    printf("����������������");
    scanf("%s", &name);

    printf("������������ߣ�cm����");
    scanf("%f", &h);

    printf("�������������أ�kg����");
    scanf("%f", &w);

    printf("========= ����Ϊ��ת�� =========\n");

    h = h * 0.3937008;
    w = w * 2.2046226;

    printf("%s�������%.2f��in����������%f��lb����\n", name, h, w);

    return 0;
}
