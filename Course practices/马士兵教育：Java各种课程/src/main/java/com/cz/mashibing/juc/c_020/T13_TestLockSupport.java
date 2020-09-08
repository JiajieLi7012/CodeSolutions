package com.cz.mashibing.juc.c_020;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.LockSupport;

public class T13_TestLockSupport
{
    public static void main(String[] args)
    {
        Thread t = new Thread(() ->
        {
            for (int i = 0; i < 10; i++)
            {
                System.out.println(i);
                // if (i == 5)
                if (i == 5 || i == 7)
                {
                    // ��ǰ�߳�ֹͣ
                    LockSupport.park();
                }
                try
                {
                    TimeUnit.SECONDS.sleep(1);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        });

        t.start();

/*        try
        {
            TimeUnit.SECONDS.sleep(8);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("after 8 senconds!");*/

        LockSupport.unpark(t); // ���̼߳���

        /* LoclSupport �ṩ�˶��̵߳Ŀ��ƹ��ܣ�
        * ��Ϊ��ʵ����������
        * ���û�е� 8 ��Ĵ�����ô t �̲߳���ͣ��
        * �� unpark ������ park ֮ǰ���ã���ʾ��ǰ����һ��
        * �������Ҫͣ���Σ��� i == 5 || i == 7 ��ʱ��ͣ
        * ���� unpark �����޷���ֹͣ�� i == 7 ��ʱ����Ϊ�䱾����ά����һ��������
        * �ʱ�ʹ��������� */

    }
}
