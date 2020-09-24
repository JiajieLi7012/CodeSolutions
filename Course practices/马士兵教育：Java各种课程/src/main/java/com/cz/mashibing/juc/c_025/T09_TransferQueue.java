package com.cz.mashibing.juc.c_025;

import java.util.concurrent.LinkedTransferQueue;

public class T09_TransferQueue
{
    public static void main(String[] args) throws InterruptedException
    {
        LinkedTransferQueue<String> strs = new LinkedTransferQueue<>();

        new Thread(() ->
        {
            try
            {
                System.out.println(strs.take());
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }).start();

        strs.transfer("aaa"); // �� transfer ��װ������������ȡ���˲��ܼ���
		// ����ȷ���ͻ��Ѿ�������Ϣ��һ�ֻ���

        //strs.put("aaa"); // �� put ����װ�����


		/*new Thread(() -> {
			try {
				System.out.println(strs.take());
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}).start();*/

    }
}
