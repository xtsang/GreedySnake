#include "startinterface.h"
#include <windows.h>
#include"tools.h"


void StartInterface::PrintFirst()//��1��ȫ���ֵĹ���
{
    SetColor(3);
    for (auto& point : startsnake)
    {   
        point.Print(); 
        Sleep(speed/4);
    }
    
}

void StartInterface::PrintFirst2()//��1��ȫ���ֵĹ���
{
    SetColor(3);
    for (auto& point : startsnake2)
    {
        point.Print();
        Sleep(speed / 4);
    }

}

void StartInterface::PrintFirst3()//��1��ȫ���ֵĹ���
{
    SetColor(4);
    for (auto& point : startsnake3)
    {
        point.Print();
        Sleep(speed / 4);
    }

}

void StartInterface::PrintSecond()//��1���������ƶ��Ĺ���
{
    for (int i = 10; i != 40; ++i) //��ͷ��Ҫ��10�ƶ���40
    {
        /*������ͷ����һ��λ�ã�������ѹ��startsnake3�У����Ƴ���������βȥ��*/
        int j = ( ((i-2)%8) < 4 )?( 15 + (i-2)%8 ) : ( 21 - (i-2)%8 );
        startsnake5.emplace_back( Point(i, j) );
        startsnake7.emplace_back(Point(40-i, j-10));
        startsnake5.back().Print();
        startsnake7.back().Print();
        startsnake5.front().Clear();
        startsnake7.front().Clear();
        startsnake5.pop_front();
        startsnake7.pop_front();
        Sleep(speed);
    }
}

void StartInterface::PrintSecond2()//��1���������ƶ��Ĺ���
{
    SetColor(4);
    for (int i = 10; i != 40; ++i) //��ͷ��Ҫ��10�ƶ���40
    {
        /*������ͷ����һ��λ�ã�������ѹ��startsnake3�У����Ƴ���������βȥ��*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake4.emplace_back(Point(40-i, j));
        startsnake6.emplace_back(Point(i, j - 10));
        startsnake4.back().Print();
        startsnake6.back().Print();
        startsnake4.front().Clear();
        startsnake6.front().Clear();
        startsnake4.pop_front();
        startsnake6.pop_front();
        Sleep(speed);
    }
}

void StartInterface::PrintSecond3()//��1���������ƶ��Ĺ���
{
    SetColor(4);
    for (int i = 10; i != 20; ++i) //��ͷ��Ҫ��10�ƶ���40
    {
        /*������ͷ����һ��λ�ã�������ѹ��startsnake3�У����Ƴ���������βȥ��*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake8.emplace_back(Point(i, j));
        startsnake9.emplace_back(Point(40-i, j ));
        startsnake8.back().Print();
        startsnake9.back().Print();
        startsnake8.front().Clear();
        startsnake9.front().Clear();
        startsnake8.pop_front();
        startsnake9.pop_front();
        Sleep(speed);
    }
}

void StartInterface::PrintFive()//�ߴӽӴ��ұߵ���ʧ�Ĺ���
{
    while (  textsnake.back().GetX() < 33 ) //���߻�û��ʧ������û�ƶ���ָ��λ��
    {
        SetColor(3);
        ClearText();//�����������
        PrintText();//���Ƹ���λ�ú������
        Sleep(speed);
    }
}


void StartInterface::PrintThird()//�ߴӽӴ��ұߵ���ʧ�Ĺ���,1
{
    while (!startsnake5.empty() ) //���߻�û��ʧ������û�ƶ���ָ��λ��
    {
        if (!startsnake5.empty()) //����߻�û��ʧ�������ƶ�
        {
            startsnake5.front().Clear();
            startsnake7.front().Clear();
            startsnake5.pop_front();
            startsnake7.pop_front();
        }
        Sleep(speed/2);
    }
}

void StartInterface::PrintThird2()//�ߴӽӴ��ұߵ���ʧ�Ĺ���,1
{
    while (!startsnake4.empty()) //���߻�û��ʧ������û�ƶ���ָ��λ��
    {
        if (!startsnake4.empty()) //����߻�û��ʧ�������ƶ�
        {
            startsnake4.front().Clear();
            startsnake6.front().Clear();
            startsnake4.pop_front();
            startsnake6.pop_front();
        }
        Sleep(speed/2);
    }
}

void StartInterface::PrintThird3()//�ߴӽӴ��ұߵ���ʧ�Ĺ���,1
{
    while (!startsnake8.empty()) //���߻�û��ʧ������û�ƶ���ָ��λ��
    {
        if (!startsnake8.empty()) //����߻�û��ʧ�������ƶ�
        {
            startsnake8.front().Clear();
            startsnake9.front().Clear();
            startsnake8.pop_front();
            startsnake9.pop_front();
        }
        Sleep(speed/2);
    }
}




void StartInterface::PrintText()
{
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}

void StartInterface::ClearText()
{
    for (auto& point : textsnake) //�����ͬʱ���������������ƶ�һ��
    {
        if (point.GetX() >= 0)
            point.Clear();
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void StartInterface::Action()
{
   
    PrintFirst();/*��1¶ͷ*/
    PrintSecond();
    PrintThird();
    PrintFirst2();/*��1¶ͷ*/
    PrintSecond2();
    PrintThird2();
    PrintFirst3();/*��1¶ͷ*/
    PrintSecond3();
    PrintThird3();
    PrintFive();
}

