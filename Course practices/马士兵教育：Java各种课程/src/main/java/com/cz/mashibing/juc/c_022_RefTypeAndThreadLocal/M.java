package com.cz.mashibing.juc.c_022_RefTypeAndThreadLocal;

public class M
{
    @Override
    protected void finalize() throws Throwable
    {
        /* һ�������������յ�ʱ������ finalize ����
        ������д���������Ŀ����Ϊ�˿�ʲôʱ�� gc
        * */
        System.out.println("finalize");
    }
}
