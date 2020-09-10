/**
 * �����������⣺���Ա�����
 * ʵ��һ���������ṩ����������add��size
 * д�����̣߳��߳�1���10��Ԫ�ص������У��߳�2ʵ�ּ��Ԫ�صĸ�������������5��ʱ���߳�2������ʾ������
 * <p>
 * ��lists���volatile֮��t2�ܹ��ӵ�֪ͨ�����ǣ�t2�̵߳���ѭ�����˷�cpu�����������ѭ��������ô���أ�
 * <p>
 * ����ʹ��wait��notify������wait���ͷ�������notify�����ͷ���
 * ��Ҫע����ǣ��������ַ���������Ҫ��֤t2��ִ�У�Ҳ����������t2�����ſ���
 * <p>
 * �Ķ�����ĳ��򣬲�����������
 * ���Զ���������������size=5ʱt2�˳�������t1����ʱt2�Ž��յ�֪ͨ���˳�
 * ��������Ϊʲô��
 * <p>
 * notify֮��t1�����ͷ�����t2�˳���Ҳ����notify��֪ͨt1����ִ��
 * ����ͨ�Ź��̱ȽϷ���
 * <p>
 * ʹ��Latch�����ţ����wait notify������֪ͨ
 * �ô���ͨ�ŷ�ʽ�򵥣�ͬʱҲ����ָ���ȴ�ʱ��
 * ʹ��await��countdown�������wait��notify
 * CountDownLatch���漰��������count��ֵΪ��ʱ��ǰ�̼߳�������
 * �����漰ͬ����ֻ���漰�߳�ͨ�ŵ�ʱ����synchronized + wait/notify���Ե�̫����
 * ��ʱӦ�ÿ���countdownlatch/cyclicbarrier/semaphore
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_020_01_Interview;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

public class T05_CountDownLatch
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

        CountDownLatch latch = new CountDownLatch(1);

        new Thread(() ->
        {
            System.out.println("t2����");
            if (c.size() != 5)
            {
                try
                {
                    latch.await();

                    //Ҳ����ָ���ȴ�ʱ��
                    //latch.await(5000, TimeUnit.MILLISECONDS);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
            System.out.println("t2 ����");

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
                    latch.countDown();
                }
				/*
				* �����˯ 1s��
				* ���ӡ��ȷ�����
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

				���û��˯ 1s
				����ӡ����������
				t2����
				t1����
				add 0
				add 1
				add 2
				add 3
				add 4
				add 5
				add 6
				t2 ����
				add 7
				add 8
				add 9
				������Ϊ t1 ����˨�� t2 ����������ӡ
				t1 �ͼ��������Ԫ�ز���ӡ��
				���������ʹ��������˨
				*
				* */
/*				try
				{
					TimeUnit.SECONDS.sleep(1);
				}
				catch (InterruptedException e)
				{
					e.printStackTrace();
				}*/
            }

        }, "t1").start();

    }
}