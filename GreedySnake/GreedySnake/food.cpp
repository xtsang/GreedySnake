#include "food.h"
#include "snake.h"
#include "map.h"
#include "point.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>


void Food::DrawFood(Snake& csnake_A, Snake& csnake_B, Map& map)//����ʳ��
{
    /*����rand����������꣬�����䷶Χ������2-29�ڣ����ڵ�ͼ�ڣ������õ������������ص��������»�ȡ��
      ͬʱÿ5��ʳ��ͳ���һ����ʱʳ��*/
    while (true)
    {
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if(tmp_x < 2) tmp_x += 2;
        if(tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto& point : map.initmap)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y))  // ��ͨʳ�����ʱʳ��λ����Զ������ͬ
            {
                flag = true;
                break;
            }
        }
        for (auto& point : csnake_A.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y))  // ��ͨʳ�����ʱʳ��λ����Զ������ͬ
            {
                flag = true;
                break;
            }
        }
        for (auto& point : csnake_B.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y))
            {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        x = tmp_x;
        y = tmp_y;
        SetCursorPosition(x, y);
        SetColor(13);
        std::cout << "��" ;
        ++cnt;
        cnt %= 5;
        if (cnt == 0)
        {
            DrawBigFood(csnake_A, csnake_B, map);
        }
        break;
    }
}

void Food::DrawBigFood(Snake& csnake_A, Snake& csnake_B, Map& map)//������ʱʳ��
{
    SetCursorPosition(5, 0);
    SetColor(11);
    std::cout << "------------------------------------------" ;//������
    progress_bar = 42;
    while (true)
    {
        int tmp_x = rand() % 30;
        int tmp_y = rand() % 30;
        if(tmp_x < 2) tmp_x += 2;
        if(tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto& point : map.initmap)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y))  // ��ͨʳ�����ʱʳ��λ����Զ������ͬ
            {
                flag = true;
                break;
            }
        }
        for (auto& point : csnake_A.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
            {
                flag = true;
                break;
            }
        }
        for (auto& point : csnake_B.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
            {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        big_x = tmp_x;
        big_y = tmp_y;
        SetCursorPosition(big_x, big_y);
        SetColor(205);
        std::cout << "��" ;
        big_flag = true;
        flash_flag = true;
        break;
    }
}

int Food::GetCnt()
{
    return cnt;
}

void Food::FlashBigFood()//��˸��ʱʳ��
{
    SetCursorPosition(big_x, big_y);
    SetColor(205);
    if (flash_flag)
    {
        std::cout << "  " ;
        flash_flag = false;
    }
    else
    {
        std::cout << "��" ;
        flash_flag = true;
    }

    SetCursorPosition(26, 0);
    SetColor(11);
    for (int i = 42; i >= progress_bar; --i)//����������
        std::cout << "\b \b" ;
    --progress_bar;
    if (progress_bar == 0) {
        SetCursorPosition(big_x, big_y);
        std::cout << "  " ;
        big_flag = false;
        big_x = 0;
        big_y = 0;
    }
}

bool Food::GetBigFlag()
{
    return big_flag;
}

int Food::GetProgressBar()
{
    return progress_bar;
}
