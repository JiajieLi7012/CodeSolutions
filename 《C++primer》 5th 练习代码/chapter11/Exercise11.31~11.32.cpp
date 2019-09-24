/*
 @Date    : 2017-12-29 10:00:38
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p440
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
using namespace std::placeholders;

void print_books(const multimap<string, string> &books)
{
    cout << "��Ŀ�а�����" << endl;
    for (auto &book : books)
    {
        cout << book.first << ": ��" << book.second << "��" << endl;
    }
    return;
}

void remove_author(multimap<string, string> &books, const string &author)
{
    auto pos = books.equal_range(author);
    if (pos.first == pos.second)
    {
        cout << "û���ҵ�������" << endl;
    }
    else
    {
        books.erase(pos.first, pos.second);
    }
    return;
}

int main(int argc, char const *argv[])
{
    multimap<string, string> books;
    books.insert({"BJ", "ABD"});
    books.insert({"BJ", "ABC"});
    books.insert({"��ӹ", "���Ӣ�۴�"});
    books.insert({"��ӹ", "�����˲�"});

    print_books(books);

    remove_author(books, "����");

    remove_author(books, "BJ");
    print_books(books);
    return 0;
}
