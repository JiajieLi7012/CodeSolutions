/*
 @Date    : 2018-05-02 13:28:36
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�����ͷ��
 */

#ifndef THREE_PHASE_OUTLET_H
#define THREE_PHASE_OUTLET_H

#include <iostream>

using namespace std;

class ThreePhaseOutlet
{
public:
    virtual ~ThreePhaseOutlet() = default;
    void do_three_phase_plugin()
    {
        cout << "�����ͷǿ�Ʋ���" << endl;
        return;
    }
};

#endif // THREE_PHASE_OUTLET_H


