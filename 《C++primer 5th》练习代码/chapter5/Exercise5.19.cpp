/*
 @Date    : 2017-12-17 21:23:28
 @Author  : 酸饺� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p190
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;
    do
    {
        cout << "�����������ַ�����";
        cin >> s1 >> s2;
        cout << "�϶̵��ַ����ǣ�" <<
        (s1.size() < s2.size() ? s1 : s2) << endl;
    } while (cin);
    return 0;
}

