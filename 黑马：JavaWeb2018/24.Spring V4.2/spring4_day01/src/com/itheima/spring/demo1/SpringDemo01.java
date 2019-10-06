package com.itheima.spring.demo1;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

/**
 * (������)
 *
 * @author SourDumplings
 * @ClassName SpringDemo01
 * @Description TODO
 * @date 2019��9��21�� ����9:57:58
 * @PL https://github.com/SourDumplings
 */
public class SpringDemo01
{
    /**
     * (��ͳ��ʽ�ĵ���)
     *
     * @param
     * @return void
     * @throws
     * @Title demo1
     * @Description TODO
     */
    @Test
    public void demo1()
    {
        // UserDao userDao = new UserDaoImpl();
        UserDao userDao = new UserDaoHibernateImpl();
        userDao.save();

        UserDaoImpl userDaoImpl = new UserDaoImpl();
        userDaoImpl.setName("zhangsan");
    }

    /**
     * (Spring��ʽ����)
     *
     * @param
     * @return void
     * @throws
     * @Title demo2
     * @Description TODO
     */
    @Test
    public void demo2()
    {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        UserDao userDao = (UserDao) applicationContext.getBean("UserDao");
        userDao.save();
    }

    /**
     * ���ش����ϵ������ļ�
     *
     * @param
     * @return void
     * @throws
     * @description: TODO
     * @author CHANG Zheng
     * @date 2019/10/6 22:41
     */
    @Test
    public void demo3()
    {
		ApplicationContext applicationContext = new FileSystemXmlApplicationContext("C:\\Users\\sourd\\Downloads\\applicationContext.xml");
		UserDao userDao = (UserDao) applicationContext.getBean("UserDao");
		userDao.save();
    }
}
