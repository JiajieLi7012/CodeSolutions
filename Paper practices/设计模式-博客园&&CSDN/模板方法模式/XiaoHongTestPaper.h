/*
 @Date    : 2018-05-01 11:16:51
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
С���Ծ���
 */

#ifndef XIAO_HONG_TEST_PAPER_H
#define XIAO_HONG_TEST_PAPER_H

#include "TestPaper.h"
#include <iostream>

using namespace std;

class XiaoHongTestPaper: public TestPaper
{
public:
    void StudentName()
    {
        cout << "������С��" << endl;
    }
    void AnswerOne()
    {
        cout << "������X,���Ź��ң�����һ����������" << endl << endl;
    }
    void AnswerTwo()
    {
        cout << "����������������ϲ���Ľ�Ŀ����" << endl << endl;
    }
};

#endif // XIAO_HONG_TEST_PAPER_H


