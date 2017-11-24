#include <stdio.h>
#include <stdlib.h>

// 思路

// 上了陈越、何钦铭老师的MOOC的同学（没上过也可能）应该记得一个“最大子列和”问题。陈越老师从O(N^3)的方案一直讲到O(N)的方案，其实就是思路的优化。这道题有很相似的特性。
// 当然这道题应该没有O(N)的方案，因为这个需要排好序，所以至少是O(N log(N))。不过如果看排好序后的时间消耗，是可以达到O(N)的。

// 先对数组进行非递减排序。
// 设置两个指针，分别代表完美数列的开头和结尾。
// 每次我们都将结尾指向刚刚开始大于开头的一个数，二者距离就是目前完美数列的最长长度。
// 开头指针向下进行遍历，这个时候结尾指针只需从原位置开始向下遍历即可，因为新的开头的数一定更大，那么结尾的数一定不会小于上次的值。
// 这样我们所用的时间就是开头和结尾分别一次遍历的时间，就是2N，完成O(N)的目标。

// 代码实现：

// 题目给的数字都是小于10^9的，但是在判断M <= m * p的时候，m * p是可能大于32位整型范围的，要合理处理这个数字。

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, p;
    scanf("%d %d", &N, &p);
    int a[N];
    int i, first;
    int max = 0;
    int last = 0;
    long long product;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, N, sizeof(int), compare);

    for (first = 0; first < N; first++)
    {
        product = 1L * a[first] * p;
        for (; last < N && a[last] <= product; last++);
        if (last - first > max)
        {
            max = last - first;
        }
    }
    printf("%d\n", max);
    return 0;
}
