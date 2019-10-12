/*
 @Date    : 2018-05-05 19:37:36
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
�������ڽ�������ʦ��û������ͬѧ���ڸ��Ÿ������飬С�����ڴ���Ϸ��С�����ڳ���ҵ.....,  ����ͬѧ��Ҫ��೤���Եף�������ʦ������ʦ����֪ͨ���һ����Ȼ�����Ϸ������ֹͣ������ҵ��Ҳֹͣ��
����೤�൱����һ��֪ͨ�ߣ� С�š�С��Լ�����ͬѧ��Ȼ�Ǽ����ߣ����Ǽ����˰೤�ǵ���Ϣ��һ����ʦ�������ϲ�ȡ��ص��ж���
���ȣ��Ȱ�֪ͨ�����Ϊ����Ϊһ���ӿڣ���Ϊ��������ܼ����Ķ�����ͬ������ѧϰίԱ������������ʦ���೤������ѧ��ʦ�ȵȣ�������������������Ӽ���û����ô��ϸ����
ע��ͬѧ�Ǽ����ߣ��೤��֪ͨ�ߣ��о��е�С��Ť����������Ӿ�������������
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <list>
#include <algorithm>
#include <memory>

using namespace std;

// �����߳����࣬����Ҫʵ�ֱ�֪ͨ�Ľӿ�
class TeacherListener
{
public:
    virtual void teacher_coming() = 0;
    virtual void do_bad_thing() = 0;
};

// �����߾�����
class XiaoZhang: public TeacherListener
{
public:
    void teacher_coming() override
    {
        stop_copy();
        return;
    }
    void do_bad_thing() override
    {
        copy_homework();
        return;
    }
private:
    void stop_copy()
    {
        cout << "��ʦ���ˣ�ֹͣ����ҵ��" << endl;
        return;
    }
    void copy_homework()
    {
        cout << "С�ų���ҵ������" << endl;
        return;
    }
};

class XiaoLi: public TeacherListener
{
public:
    void teacher_coming() override
    {
        stop_play_game();
        return;
    }
    void do_bad_thing() override
    {
        play_game();
        return;
    }
private:
    void stop_play_game()
    {
        cout << "��ʦ���ˣ�ֹͣ����Ϸ��" << endl;
        return;
    }
    void play_game()
    {
        cout << "С�����Ϸ������" << endl;
        return;
    }
};


// ֪ͨ�߳�����,�����������࣬Ҫʵ����ɾ�����ߺ�֪ͨ�����߽ӿ�
class Notifier
{
public:
    virtual void add_listener(const shared_ptr<TeacherListener> &pTeacherListener) = 0;
    virtual void remove_listener(const shared_ptr<TeacherListener> &pTeacherListener) = 0;
    virtual void notify() = 0;
};

// �೤����֪ͨ�߾�����
class Moniter: public Notifier
{
public:
    void add_listener(const shared_ptr<TeacherListener> &pTeacherListener) override
    {
        m_listeners.push_back(pTeacherListener);
        cout << "�೤��æ����" << endl;
        return;
    }
    void remove_listener(const shared_ptr<TeacherListener> &pTeacherListener) override
    {
        auto it = find(m_listeners.begin(), m_listeners.end(), pTeacherListener);
        m_listeners.erase(it);
        return;
    }
    void notify() override
    {
        cout << "�೤����ʦ������" << endl;
        for (auto &pTeacherListener : m_listeners)
        {
            pTeacherListener->teacher_coming();
        }
        return;
    }
private:
    list<shared_ptr<TeacherListener>> m_listeners;
};

int main(int argc, char const *argv[])
{
    shared_ptr<Notifier> m(new Moniter);
    shared_ptr<TeacherListener> xz(new XiaoZhang), xl(new XiaoLi);
    m->add_listener(xz);
    xz->do_bad_thing();
    m->add_listener(xl);
    xl->do_bad_thing();

    m->notify();

    return 0;
}

