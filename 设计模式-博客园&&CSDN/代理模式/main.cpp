/*
 @Date    : 2018-04-25 09:58:49
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�������������˽��������˽���������˼��ѽ��զ�죬���Ǹ��������������������˼�����ӳ���һ�������顶24�����ģʽ������6�����ԭ��.pdf����
�����漰���Ķ������£�
����main(),������
����CSubject,�ӿ�
����CWangPo,��������
����CPanJinLian,ʵ��ִ����֮һ���˽���
����CJiaShi,ʵ��ִ����֮�������ϣ������ߵ��Զ��Դ�...��
����˵���������ʵ��ִ���������ڹ�ͬ�Ľӿڣ�����ӵ��ʵ��ִ���ߵ�ʵ���������ÿһ���������ӿڵ�ʵ�ֺ�������ֱ�ӵ���ʵ��ִ���ߵĶ�Ӧ�ӿں�����
����ע�⣺����ֻ�Ǽ򵥵�װ�أ�Ȼ�����ʵ��ִ���ߵĺ�����
 */

#include "stdafx.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // call ����
    shared_ptr<Wangpo> pWangpo;
    // ����������˽�����Щʲô�����Ű���
    printf("\n����������˽�����Щʲô�����Ű���\n");
    pWangpo = make_shared<Wangpo>(make_shared<Panjinlian>());
    pWangpo->makeEyesWithMan();
    pWangpo->makeLoveWithMan();

    // ��������ͼ��ϸ�Щ���飬���Ű���
    printf("\n��������ͼ��ϸ�Щ���飬���Ű���\n");
    pWangpo = make_shared<Wangpo>(make_shared<Jiashi>());
    pWangpo->makeEyesWithMan();
    pWangpo->makeLoveWithMan();
    return 0;
}

