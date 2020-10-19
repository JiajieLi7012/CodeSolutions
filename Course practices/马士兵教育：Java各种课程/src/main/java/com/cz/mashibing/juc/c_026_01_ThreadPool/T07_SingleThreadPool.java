package com.cz.mashibing.juc.c_026_01_ThreadPool;

/*
* ΪʲôҪ�е��̵߳��̳߳أ�
* 1.������й���
* 2.�������ڹ���
* */

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class T07_SingleThreadPool
{
    public static void main(String[] args)
    {
        // �̳߳صĹ��������� Executors
        ExecutorService service = Executors.newSingleThreadExecutor();
        for (int i = 0; i < 5; i++)
        {
            final int j = i;
            service.execute(() ->
            {

                System.out.println(j + " " + Thread.currentThread().getName());
            });
        }

    }
}
