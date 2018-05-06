/*
 @Date    : 2018-05-03 19:13:59
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
����������ϲ����ױ����ÿ�������վ����ž��Ӷ���ױ����ױ��ʱ��ҪͿ�ں죬����ë��Ĩ��ˮ��
���Ż�ױ��������̱���һ�����͵�װ����ģʽ�����ں죬���߱ʣ���ˮ����Ȼ����װ��Ʒ��
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// ���վ��ӵ�Ů��
class Women
{
public:
    virtual void look_into_the_mirror() = 0;
};

// ��Ҫװ�ε���
class Wife : public Women
{
public:
    void look_into_the_mirror()
    {
        cout << "�����е����� " << endl;
        return;
    }
};

class Sister : public Women
{
public:
    void look_into_the_mirror()
    {
        cout << "�����е����� " << endl;
        return;
    }
};

// һ����ױ��Ů�ˣ�װ��Ʒ�ĳ�����ࣩ
class DecoratorWomen : public Women
{
public:
    DecoratorWomen(const shared_ptr<Women> &woman)
        : m_women(woman)
    {

    }

    void look_into_the_mirror()
    {
        m_women->look_into_the_mirror();
        make_up();
    }
    virtual void make_up() = 0; //��ױ
protected:
    shared_ptr<Women> m_women;
};

// ��ױƷ
class Lipstick : public DecoratorWomen
{
public:
    Lipstick(const shared_ptr<Women> &woman): DecoratorWomen(woman) {};
    void make_up()
    {
        cout << "�л����촽��" << endl;
    }
};


class Mascara : public DecoratorWomen
{
public:
    Mascara(const shared_ptr<Women> &woman): DecoratorWomen(woman) {};
    void make_up()
    {
        cout << "�кںڵĽ�ë��" << endl;
    }
};

class Perfume : public DecoratorWomen
{
public:
    Perfume(const shared_ptr<Women> &woman): DecoratorWomen(woman) {};
    void make_up()
    {
        cout << "�����ζ���ζ����" << endl;
    }
};

int main(int argc, char const *argv[])
{
    shared_ptr<Women> myWife(new Wife());
    shared_ptr<Lipstick> lips(new Lipstick(myWife));
    shared_ptr<Mascara> mas(new Mascara(lips));
    shared_ptr<Perfume> per(new Perfume(mas));
    myWife = per;
    myWife->look_into_the_mirror();

    cout << "..................." << endl;

    shared_ptr<Women> mySister(new Sister());
    shared_ptr<Lipstick> lips1(new Lipstick(mySister));
    shared_ptr<Perfume> per1(new Perfume(lips1));
    mySister = per1;
    mySister->look_into_the_mirror();
    return 0;
}

