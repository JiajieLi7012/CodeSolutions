/**
 * �����������⣺���Ա�����
 * ʵ��һ���������ṩ����������add��size
 * д�����̣߳��߳�1���10��Ԫ�ص������У��߳�2ʵ�ּ��Ԫ�صĸ�������������5��ʱ���߳�2������ʾ������
 * <p>
 * ��lists���volatile֮��t2�ܹ��ӵ�֪ͨ�����ǣ�t2�̵߳���ѭ�����˷�cpu�����������ѭ����
 * ���ң������if �� break֮�䱻����̴߳�ϣ��õ��Ľ��Ҳ����ȷ��
 * ����ô���أ�
 *
 * @author mashibing
 */
package com.cz.mashibing.juc.c_020_01_Interview;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.TimeUnit;


public class T02_WithVolatile
{

    //��� volatile��ʹt2�ܹ��õ�֪ͨ
	/* �����
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
	�õ�����ȷ�����������˵ volatile ���ε������ã�
	��������Ķ�������� volatile ��û���õģ������ȷ��һ��żȻ�ԣ�
	�����˯�� 1s ȥ����ܴ���ܲ��ܵõ���ȷ�������
	*/
    // volatile List lists = new LinkedList();

	/* ���������Ҳû���ã��ȽϹ���
	* �����˯ 1s ���ǲ��ܱ�֤�õ���ȷ�����
	* ֻ�ܽ���Ϊ������ hotspot ʵ��ʱ������һ���߳�˯��ʱ����
	* ��� volatile ���ã���Ҫ������������ */
    volatile List lists = Collections.synchronizedList(new LinkedList<>());


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

        T02_WithVolatile c = new T02_WithVolatile();
        new Thread(() ->
        {
            for (int i = 0; i < 10; i++)
            {
                c.add(new Object());
                System.out.println("add " + i);

                /*try
                {
                    TimeUnit.SECONDS.sleep(1);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                }*/
            }
        }, "t1").start();

        new Thread(() ->
        {
            while (true)
            {
                if (c.size() == 5)
                {
                    break;
                }
            }
            System.out.println("t2 ����");
        }, "t2").start();
    }
}