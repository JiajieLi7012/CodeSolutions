package com.cz.mashibing.juc.c_020_01_Interview;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

/**
 * ��� T05 �����⣬ʹ��������˨������Դ�ӡ����ȷ���
 t2����
 t1����
 add 0
 add 1
 add 2
 add 3
 add 4
 t2 ����
 add 5
 add 6
 add 7
 add 8
 add 9
 *
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName ��ʿ��������Java���ֿγ�
 * @date 2020/9/10 20:55
 */
public class T05_TwoCountDownLatch
{
    // ���volatile��ʹt2�ܹ��õ�֪ͨ�����˸о�û��Ҫ�� volatile
    // volatile List lists = new ArrayList();

    List lists = new ArrayList();

    public void add(Object o)
    {
        lists.add(o);
    }

    public int size()
    {
        return lists.size();
    }

    public static void main(String[] args)
    {
        T05_CountDownLatch c = new T05_CountDownLatch();

        CountDownLatch latch1 = new CountDownLatch(1);
        CountDownLatch latch2 = new CountDownLatch(1);

        new Thread(() ->
        {
            System.out.println("t2����");
            if (c.size() != 5)
            {
                try
                {
                    latch2.await();

                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
            System.out.println("t2 ����");

            // ���� t1
            latch1.countDown();

        }, "t2").start();

        try
        {
            TimeUnit.SECONDS.sleep(1);
        }
        catch (InterruptedException e1)
        {
            e1.printStackTrace();
        }

        new Thread(() ->
        {
            System.out.println("t1����");
            for (int i = 0; i < 10; i++)
            {
                c.add(new Object());
                System.out.println("add " + i);

                if (c.size() == 5)
                {
                    // �����ţ���t2����ִ��
                    latch2.countDown();

                    // ˩ס t1���� t2 �ȴ�ӡ
                    try
                    {
                        latch1.await();
                    }
                    catch (InterruptedException e)
                    {
                        e.printStackTrace();
                    }
                }
            }

        }, "t1").start();

    }
}
