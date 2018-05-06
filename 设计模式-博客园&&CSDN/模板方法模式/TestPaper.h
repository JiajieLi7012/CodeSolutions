/*
 @Date    : 2018-05-01 11:10:19
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�Ծ������
 */

#ifndef TEST_PAPER_H
#define TEST_PAPER_H

#include <iostream>

using namespace std;

class TestPaper
{
public:
    void DoTestPaper()
    {
        StudentName();
        TestTitleOne();
        TestTitleTwo();
    };

    void TestTitleOne()
    {
        cout << "��Ŀһ��X���ķ��ۻή����ô��" << endl;
        AnswerOne();
    }

    void TestTitleTwo()
    {
        cout << "��Ŀ����˵˵������������Ŀ�����" << endl;
        AnswerTwo();
    }

    virtual void AnswerOne() = 0;
    virtual void AnswerTwo() = 0;
    virtual void StudentName() = 0;
    virtual ~TestPaper() {}
};

#endif // TEST_PAPER_H


