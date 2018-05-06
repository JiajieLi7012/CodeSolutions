/*
 @Date    : 2018-04-24 18:37:46
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
����ģʽ

���ƻ�������ȥȢ�ף�������������������������

main(),����
����CContext,����
����CStrategy,���Գ�����
����CBackDoor,����֮һ
����CGivenGreenLight,����֮��
����CBlockEnemy,����֮��
����˵����һ�����Էŵ�һ����������õ�ʱ���ҵ�������ң��ӽ������ó�������ʹ�á�
����ע�⣺����ֻ�Ǽ򵥵�װ�غ͵��ò��ԣ�������û���߼������Ի��и��������Ȩ�����и�����߼���
 */

#include "stdafx.h"

using namespace std;

int main(int argc, char const *argv[])
{
    std::shared_ptr<Context> pContext; // ����

    printf("\n----------�ոյ������ʱ����һ��----------\n");
    pContext = make_shared<Context>(make_shared<BackDoor>()); // ��һ������
    pContext->openAndOperate();

    printf("\n---------�����ֲ�˼���ˣ���ڶ�����----------\n");
    pContext = make_shared<Context>(make_shared<GivenGreenLight>());
    pContext->openAndOperate();

    printf("\n----------��Ȩ��С��׷�ˣ�զ�죿�������----------\n");
    pContext = make_shared<Context>(make_shared<BlockEnemy>());
    pContext->openAndOperate();

    return 0;
}

