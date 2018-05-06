/*
 @Date    : 2018-04-26 14:15:40
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
˼·��
ָ��ʵ���ĸ���->��һ���������洢ʵ��->����һ�����������ڲ���ָ����ʵ��
��Ȼ���͵���ģʽһ����Ҳ��Ҫ�����캯��˽�л�
ͬʱ��ʵ�������������������ȱ�������ÿ��ʵ�����еģ�����Ӧ����Ϊ��̬��

������֮ǰ����ģʽ���ᵽ�Ļʵ۵����ӣ������м����ʵ۰�0.0
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <memory>
#include <ctime>

using namespace std;

class Emperor
{
private:
    Emperor(const string &name);
    // ��������ܲ�����ʵ������
    static int maxNumOfEmperor;
    // ÿ��emperor����name����һ��vector������
    static vector<string> nameList;
    // ����һ��vector��������ʵ��
    static vector<shared_ptr<Emperor>> emperorList;
    // ��ǰemperor�����к�
    static int indexOfEmperor;
public:
    ~Emperor();
    // ��������ʵ��
    static void produce_all_instances();
    // ��ȡʵ��
    static shared_ptr<Emperor> get_instance();
    // ʵ������Ϊ
    static void emperor_say();
};

// ���о�̬��Ա�������ʼ��
int Emperor::indexOfEmperor = 0;
int Emperor::maxNumOfEmperor = 3;
vector<string> Emperor::nameList;
vector<shared_ptr<Emperor>> Emperor::emperorList;

Emperor::Emperor(const string &name)
{
    cout << "c" << endl;
    nameList.push_back(name);
    return;
}

Emperor::~Emperor() { cout << "d" << endl; }

void Emperor::produce_all_instances()
{
    for (unsigned i = 0; i < maxNumOfEmperor; ++i)
    {
        string name = "Emperor" + to_string(i+1);
        emperorList.push_back(shared_ptr<Emperor>(new Emperor(name)));
        nameList.push_back(name);
    }
    return;
}

shared_ptr<Emperor> Emperor::get_instance()
{
    // ������һ��Emperorʵ��
    indexOfEmperor = rand() % maxNumOfEmperor;
    return emperorList[indexOfEmperor];
}

void Emperor::emperor_say()
{
    printf("I am %s\n", nameList[indexOfEmperor].c_str());
    return;
}

int main(int argc, char const *argv[])
{
    // ���Ȳ���ʵ��
    Emperor::produce_all_instances();
    // ������5λMinisters���ΰ�
    int ministerNum = 5;
    srand(time(0));
    for (unsigned i = 0; i < ministerNum; ++i)
    {
        shared_ptr<Emperor> emperor = Emperor::get_instance();
        printf("��%d��Minister�ΰݵ��ǣ�\n", i+1);
        emperor->emperor_say();
    }
    return 0;
}

