/*
 @Date    : 2018-05-02 10:20:04
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
С�ŵ��Ծ�
 */

#ifndef XIAO_ZHANG_TEST_PAPER_H
#define XIAO_ZHANG_TEST_PAPER_H

#include "TestPaper.h"

class XiaoZhangTestPaper: public TestPaper
{
public:
    void StudentName()
    {
        cout << "������С��" << endl;
    }
    void AnswerOne()
    {
        cout << "�𣺺Ǻǣ�����ȥ�����X���ΰɡ�" << endl << endl;
    }
    void AnswerTwo()
    {
        cout << "���Һ��Ҹ�" << endl << endl;
    }
};

#endif // XIAO_ZHANG_TEST_PAPER_H

