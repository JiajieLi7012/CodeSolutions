#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include<stdio.h>

int main()
{
    double halfPi=0;
    double numerator=1,denominator=1;//���ӣ���ĸ:һ��Ҫ����Ϊdouble���ͣ����򲿷ִ𰸲�ͨ��
    double givenThreshold; //������ֵ
    scanf("%lf",&givenThreshold);

    double threshold=numerator*1.0/denominator;
    int i=0;
    while(threshold>=givenThreshold)
    {
        halfPi+=threshold;
        ++i;
        //printf("%d/%d\n",numerator,denominator);
        numerator*=i;
        denominator*=(2*i+1);
        threshold=numerator*1.0/denominator;
    }
    halfPi+=threshold;
    printf("%0.6f\n",halfPi*2);
    return 0;
}
