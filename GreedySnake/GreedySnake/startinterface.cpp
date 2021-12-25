#include "startinterface.h"
#include <windows.h>
#include"tools.h"


void StartInterface::PrintFirst()//蛇1完全出现的过程
{
    SetColor(3);
    for (auto& point : startsnake)
    {   
        point.Print(); 
        Sleep(speed/4);
    }
    
}

void StartInterface::PrintFirst2()//蛇1完全出现的过程
{
    SetColor(3);
    for (auto& point : startsnake2)
    {
        point.Print();
        Sleep(speed / 4);
    }

}

void StartInterface::PrintFirst3()//蛇1完全出现的过程
{
    SetColor(4);
    for (auto& point : startsnake3)
    {
        point.Print();
        Sleep(speed / 4);
    }

}

void StartInterface::PrintSecond()//蛇1从左向右移动的过程
{
    for (int i = 10; i != 40; ++i) //蛇头需要从10移动到40
    {
        /*计算蛇头的下一个位置，并将其压入startsnake3中，绘制出来，将蛇尾去掉*/
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

void StartInterface::PrintSecond2()//蛇1从左向右移动的过程
{
    SetColor(4);
    for (int i = 10; i != 40; ++i) //蛇头需要从10移动到40
    {
        /*计算蛇头的下一个位置，并将其压入startsnake3中，绘制出来，将蛇尾去掉*/
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

void StartInterface::PrintSecond3()//蛇1从左向右移动的过程
{
    SetColor(4);
    for (int i = 10; i != 20; ++i) //蛇头需要从10移动到40
    {
        /*计算蛇头的下一个位置，并将其压入startsnake3中，绘制出来，将蛇尾去掉*/
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

void StartInterface::PrintFive()//蛇从接触右边到消失的过程
{
    while (  textsnake.back().GetX() < 33 ) //当蛇还没消失或文字没移动到指定位置
    {
        SetColor(3);
        ClearText();//清除已有文字
        PrintText();//绘制更新位置后的文字
        Sleep(speed);
    }
}


void StartInterface::PrintThird()//蛇从接触右边到消失的过程,1
{
    while (!startsnake5.empty() ) //当蛇还没消失或文字没移动到指定位置
    {
        if (!startsnake5.empty()) //如果蛇还没消失，继续移动
        {
            startsnake5.front().Clear();
            startsnake7.front().Clear();
            startsnake5.pop_front();
            startsnake7.pop_front();
        }
        Sleep(speed/2);
    }
}

void StartInterface::PrintThird2()//蛇从接触右边到消失的过程,1
{
    while (!startsnake4.empty()) //当蛇还没消失或文字没移动到指定位置
    {
        if (!startsnake4.empty()) //如果蛇还没消失，继续移动
        {
            startsnake4.front().Clear();
            startsnake6.front().Clear();
            startsnake4.pop_front();
            startsnake6.pop_front();
        }
        Sleep(speed/2);
    }
}

void StartInterface::PrintThird3()//蛇从接触右边到消失的过程,1
{
    while (!startsnake8.empty()) //当蛇还没消失或文字没移动到指定位置
    {
        if (!startsnake8.empty()) //如果蛇还没消失，继续移动
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
    for (auto& point : textsnake) //清除的同时将文字整体向右移动一格
    {
        if (point.GetX() >= 0)
            point.Clear();
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void StartInterface::Action()
{
   
    PrintFirst();/*蛇1露头*/
    PrintSecond();
    PrintThird();
    PrintFirst2();/*蛇1露头*/
    PrintSecond2();
    PrintThird2();
    PrintFirst3();/*蛇1露头*/
    PrintSecond3();
    PrintThird3();
    PrintFive();
}

