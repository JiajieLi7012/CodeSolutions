/**
 * 假设你能够提供一个服务
 * 这个服务查询各大电商网站同一类产品的价格并汇总展示
 *
 * @author 马士兵 http://mashibing.com
 */

package com.cz.mashibing.juc.c_026_01_ThreadPool;

import java.io.IOException;
import java.util.Random;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;

public class T06_01_CompletableFuture
{
    public static void main(String[] args) throws ExecutionException, InterruptedException
    {
        long start, end;

        /*start = System.currentTimeMillis();

        priceOfTM();
        priceOfTB();
        priceOfJD();

        end = System.currentTimeMillis();
        System.out.println("use serial method call! " + (end - start));*/

        start = System.currentTimeMillis();

        CompletableFuture<Double> futureTM = CompletableFuture.supplyAsync(() -> priceOfTM());
        CompletableFuture<Double> futureTB = CompletableFuture.supplyAsync(() -> priceOfTB());
        CompletableFuture<Double> futureJD = CompletableFuture.supplyAsync(() -> priceOfJD());

        /* allOf 是必须要全部任务执行完才行，
        Completable 可以看成是多个 Future 任务的管理类 */
        CompletableFuture.allOf(futureTM, futureTB, futureJD).join();

        CompletableFuture.supplyAsync(() -> priceOfTM())
            .thenApply(String::valueOf)
            .thenApply(str -> "price of TM " + str)
            .thenAccept(System.out::println);

        end = System.currentTimeMillis();
        System.out.println("use completable future! " + (end - start));

        // 由于异步，如果不阻塞主线程则看不到打印 TM 的价格
/*        try
        {
            System.in.read();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }*/
    }

    private static double priceOfTM()
    {
        delay();
        return 1.00;
    }

    private static double priceOfTB()
    {
        delay();
        return 2.00;
    }

    private static double priceOfJD()
    {
        delay();
        return 3.00;
    }

    /*private static double priceOfAmazon() {
        delay();
        throw new RuntimeException("product not exist!");
    }*/

    private static void delay()
    {
        int time = new Random().nextInt(500);
        try
        {
            TimeUnit.MILLISECONDS.sleep(time);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.printf("After %s sleep!\n", time);
    }
}
