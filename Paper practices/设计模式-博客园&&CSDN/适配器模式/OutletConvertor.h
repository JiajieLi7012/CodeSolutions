/*
 @Date    : 2018-05-02 13:43:17
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
ת��ͷ�࣬����������
 */

#ifndef OUTLET_CONVERTOR_H
#define OUTLET_CONVERTOR_H

#include "ThreePhaseOutlet.h"
#include "TwoPhaseOutlet.h"

class OutletConvertor: public ThreePhaseOutlet, public TwoPhaseOutlet
{
public:
    virtual ~OutletConvertor() = default;
    void do_plugin() override
    {
        do_converter();
        do_three_phase_plugin();
        return;
    }
    void do_converter()
    {
        cout << "�����ͷתΪ�����ͷ" << endl;
        return;
    }
};

#endif // OUTLET_CONVERTOR_H


