package com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal;

import java.io.IOException;

public class T01_NormalReference
{
    public static void main(String[] args) throws IOException
    {
        /* gc �ǲ��������ͨ���ã�ǿ���ã�ָ��Ķ���� */
        M m = new M();
        m = null;
        System.gc(); //DisableExplicitGC

        System.in.read(); /* ����ס��ǰ�̣߳�gc �����ڱ���̵߳� */
    }
}
