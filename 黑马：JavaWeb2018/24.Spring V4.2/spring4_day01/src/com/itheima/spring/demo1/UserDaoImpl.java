package com.itheima.spring.demo1;

/**   
 * @ClassName  UserServiceImpl   
 * @Description TODO(�û�����ҵ���ʵ����)   
 * @author SourDumplings
 * @date   2019��9��21�� ����9:54:13   
 *     
 * @PL https://github.com/SourDumplings
 */ 
public class UserDaoImpl implements UserDao
{
	private String name;
	
	
	
	public String getName()
	{
		return name;
	}



	public void setName(String name)
	{
		this.name = name;
	}



	public void save()
	{
		// TODO Auto-generated method stub
		System.out.println("UserDaoʵ����ִ����..., name = " + name);
	}

}
