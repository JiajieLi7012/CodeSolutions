/*
 @Date    : 2018-05-06 15:50:02
 @Author  : ����� (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
RemoteControlΪң������LightOnCommandΪ�����������
LightOffCommandΪ�ص�����������Ǽ̳��Ի���Command��������ƿ���ʹ������Ժ��ֹ������װ�á�
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// ����࣬��receiver
class Light
{
public:
    void on()
    {
        cout << "�ƿ���" << endl;
        return;
    }
    void off()
    {
        cout << "�ƹ���" << endl;
        return;
    }
};

// ���������
class Command
{
public:
    virtual void execute() = 0;
};

// ���������
class LightOnCommand: public Command
{
public:
    LightOnCommand(const shared_ptr<Light> &pLight): m_light(pLight) {}
    void execute() override
    {
        m_light->on();
        return;
    }
private:
    shared_ptr<Light> m_light;
};

class LightOffCommand: public Command
{
public:
    LightOffCommand(const shared_ptr<Light> &pLight): m_light(pLight) {}
    void execute() override
    {
        m_light->off();
        return;
    }
private:
    shared_ptr<Light> m_light;
};

// ң�����࣬��invoker
class RemoteControl
{
public:
    void set_command(const shared_ptr<Command> &command)
    {
        button = command;
        return;
    }
    void press_button()
    {
        button->execute();
        return;
    }
private:
    shared_ptr<Command> button;
};

int main(int argc, char const *argv[])
{
    shared_ptr<RemoteControl> lightOnControl(new RemoteControl), lightOffControl(new RemoteControl);
    shared_ptr<Light> light;

    shared_ptr<LightOnCommand> onCommand(new LightOnCommand(light));
    shared_ptr<LightOffCommand> offCommand(new LightOffCommand(light));

    lightOnControl->set_command(onCommand);
    lightOffControl->set_command(offCommand);

    lightOnControl->press_button();
    cout << "������ˣ" << endl;
    lightOffControl->press_button();

    return 0;
}

