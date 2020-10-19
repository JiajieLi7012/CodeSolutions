package com.cz.mashibing.juc.c_026_01_ThreadPool;

import java.io.IOException;
import java.util.concurrent.*;

public class T05_00_HelloThreadPool
{

    static class Task implements Runnable
    {
        private int i;

        public Task(int i)
        {
            this.i = i;
        }

        @Override
        public void run()
        {
            System.out.println(Thread.currentThread().getName() + " Task " + i);
            try
            {
                System.in.read(); // �����ڴ�
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }

        @Override
        public String toString()
        {
            return "Task{" +
                "i=" + i +
                '}';
        }
    }

    public static void main(String[] args)
    {
        /* �̳߳���ά�����������ϣ��̼߳��Ϻ�������� */
        ThreadPoolExecutor tpe = new ThreadPoolExecutor(2, // �����߳����������ֶ��ٸ��߳�
            4, // ����߳������������չ���ж��ٸ��߳�
            60, // �̶߳೤ʱ����о͹黹������ϵͳֱ���߳����ﵽ�����߳�������Ĭ���º����̲߳��黹����Ĭ���º����߳���Զ����
            TimeUnit.SECONDS,
            new ArrayBlockingQueue<Runnable>(4), // ������У���������������
            Executors.defaultThreadFactory(), // �̹߳������󣬼��̲߳����������һ�㶼���Զ��壬�������淶
            new ThreadPoolExecutor.CallerRunsPolicy()); // �ܾ����ԣ��̳߳����߳�ȫæ�Ҵﵽ������߳����������������������ʱ�����ܾ����ԣ�һ�㶼���Զ���

        for (int i = 0; i < 8; i++)
        {
            tpe.execute(new Task(i));
        }

        System.out.println(tpe.getQueue());

        tpe.execute(new Task(100));

        System.out.println(tpe.getQueue());

        tpe.shutdown();
    }
}
