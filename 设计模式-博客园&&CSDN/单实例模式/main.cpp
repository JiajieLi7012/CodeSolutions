/*
 @Date    : 2018-04-25 13:58:50
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�ʵ�һ����˵��һ��ʱ��ֻ����һ���������ô󳼲ΰݻʵ۵�������˵����ʵ��ģʽ��
Emperor����ʵ��࣬�����������вΰݻʵۡ�
 */

#include <iostream>
#include <memory>

using namespace std;

class Emperor
{
private:
    Emperor();
    static shared_ptr<Emperor> _instance; // Ψһ�Ļʵ۵�ʵ��
public:
    static shared_ptr<Emperor> get_instance(); // �������������ʵ��
    static void emperor_say(); // ��������������������static
    ~Emperor();
};

shared_ptr<Emperor> Emperor::_instance = nullptr;

Emperor::Emperor()
{
    cout << "Emperor constructor" << endl;
    return;
}

Emperor::~Emperor() {}

shared_ptr<Emperor> Emperor::get_instance()
{
    if (_instance == nullptr)
    {
        _instance = shared_ptr<Emperor>(new Emperor);
    }
    return _instance;
}

void Emperor::emperor_say()
{
    cout << "�Ҿ��ǻʵ�ĳĳĳ������" << endl;
    return;
}


// ����
class Minister {};


int main(int argc, char const *argv[])
{
    for (unsigned day = 0; day < 3; ++day)
    {
        //��GetInstance()Ϊstaticʱ�����ܱ�֤ʵ�����౾����������
        //����һ����static��Ա�����������ض����������ܵ���
        shared_ptr<Emperor> emperor = Emperor::get_instance();
        emperor->emperor_say();
        // ������Ļʵ���ͬһ����
    }
    return 0;
}

