/**
 * ������Ҫ���������ѡ�-Xms20M -Xmx20M
 * ָ�� 20M �Ķ��ڴ�
 * �����
null
null
null
null
finalize
null
--- �����ö���jvm������ ---- java.lang.ref.PhantomReference@7c6b73ff
null
null
null
Exception in thread "Thread-0" java.lang.OutOfMemoryError: Java heap space
	at java.base/java.util.LinkedList.linkLast(LinkedList.java:146)
	at java.base/java.util.LinkedList.add(LinkedList.java:342)
	at com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal.T04_PhantomReference.lambda$main$0(T04_PhantomReference.java:47)
	at com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal.T04_PhantomReference$$Lambda$14/0x0000000100066840.run(Unknown Source)
	at java.base/java.lang.Thread.run(Thread.java:834)


 * һ�������Ƿ��������õĴ��ڣ���ȫ�����������ʱ�乹��Ӱ�죬
 * Ҳ�޷�ͨ������������ȡһ�������ʵ����
 * Ϊһ���������������ù�����ΨһĿ�ľ���������������ռ�������ʱ�յ�һ��ϵͳ֪ͨ��
 * �����ú������öԹ�������Ļ��ն��������Ӱ�죬���ֻ�������û��������ù����Ŷ���
 * ��ô�������ͻᱻ���ա����ǵĲ�֮ͬ�����������õ�get�����������õ�get����ʼ�շ���null,
 * �����ÿ���ʹ��ReferenceQueue,�����ñ������ReferenceQueueʹ�á�
 * <p>
 * jdk��ֱ���ڴ�Ļ��վ��õ������ã�����jvm�Զ��ڴ����ķ�Χ�Ƕ��ڴ棬
 * ��ֱ���ڴ����ڶ��ڴ�֮�⣨��ʵ���ڴ�ӳ���ļ�������ȥ��������ڴ�ռ����ظ����
 * ����ֱ���ڴ�ķ���ͻ��ն�����Unsafe��ȥ������java������һ��ֱ���ڴ�֮��
 * ���ڶ��ڴ����һ�����󱣴���������ڴ�����ã�
 * ������������ռ�������һ��������󱻻��գ�
 * ��Ӧ���û��̻߳��յ�֪ͨ����ֱ���ڴ������������
 * <p>
 * ��ʵ�ϣ���������һ������Ҫ����;���������������ڴ���ͷţ�
 * DirectByteBuffer����ͨ����������ʵ�ֶ����ڴ���ͷŵġ�
 */


package com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal;

import java.lang.ref.PhantomReference;
import java.lang.ref.Reference;
import java.lang.ref.ReferenceQueue;
import java.util.LinkedList;
import java.util.List;

public class T04_PhantomReference
{
    private static final List<Object> LIST = new LinkedList<>();
    private static final ReferenceQueue<M> QUEUE = new ReferenceQueue<>();


    public static void main(String[] args)
    {

        PhantomReference<M> phantomReference = new PhantomReference<>(new M(), QUEUE);

        new Thread(() ->
        {
            while (true)
            {
                LIST.add(new byte[1024 * 1024]);
                try
                {
                    Thread.sleep(1000);
                }
                catch (InterruptedException e)
                {
                    e.printStackTrace();
                    Thread.currentThread().interrupt();
                }
                /* ������ get ���ò���ֵ�� */
                System.out.println(phantomReference.get());
            }
        }).start();

        /*
        * ���������õĶ��󱻻��գ���֪ͨ
        * ֪ͨ�ķ�ʽ�ǰ�������üӵ�������
        * ����߳��������������ָ��Ķ����Ƿ񱻻���
        * */
        new Thread(() ->
        {
            while (true)
            {
                Reference<? extends M> poll = QUEUE.poll();
                if (poll != null)
                {
                    System.out.println("--- �����ö���jvm������ ---- " + poll);
                }
            }
        }).start();

        try
        {
            Thread.sleep(500);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

    }
}

