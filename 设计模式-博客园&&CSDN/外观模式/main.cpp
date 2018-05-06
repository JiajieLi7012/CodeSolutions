/*
 @Date    : 2018-05-05 21:05:19
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
 ���������һ�ٴ�ͣ���ô������Ҫ������ȥ��ˣ�Ȼ��ص��Һ��Լ����ˣ������극�Ժ�Ҫϴ���ɨ��
     ��ôһ������Ҫ3���࣬Shopper�� Cook�� Dishwasher�� �ֱ��������ˣ����ˣ�ϴ��ȹ�����
     ��Ȼ��ǳ��鷳���ܲ��ܼ�������̣���Ȼ���ԣ�ȥ�͹ݳԡ�
     �͹���ʱ����Ȼ�������ģʽ�ˣ����Ѹ��ӵĹ��̷�װ���ڲ����û����ù���ϸ�ڡ�
ʵ�ִ��룺
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Shopper
{
public:
    void go_shopping()
    {
        cout << "���" << endl;
        return;
    }
};

class Cook
{
public:
    void cook()
    {
        cout << "����" << endl;
        return;
    }
};

class DishWasher
{
public:
    void wash_dishes()
    {
        cout << "ϴ��" << endl;
        return;
    }
};

// �͹��࣬�������
class Resturant
{
public:
    void offer_a_meal()
    {
        m_shopper.go_shopping();
        m_cook.cook();
        cout << "�ϲ�" << endl;
        m_dishWasher.wash_dishes();
        return;
    }
    static shared_ptr<Resturant> get_Resturant()
    {
        if (!m_resturant)
        {
            m_resturant = shared_ptr<Resturant>(new Resturant);
        }
        return m_resturant;
    }
private:
    Resturant()
    {
        cout << "һ�Ҳ͹ݸ�������" << endl;
        return;
    }
    static shared_ptr<Resturant> m_resturant;
    Shopper m_shopper;
    Cook m_cook;
    DishWasher m_dishWasher;
};

shared_ptr<Resturant> Resturant::m_resturant = nullptr;

int main(int argc, char const *argv[])
{
    auto r = Resturant::get_Resturant();
    cout << "�¹���" << endl;
    r->offer_a_meal();
    return 0;
}

