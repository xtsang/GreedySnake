#include "snake.h"
#include <conio.h>
#include "tools.h"
#include <iostream>
#include "map.h"

void Snake::InitSnake()  // ��ʼ����
{
    SetColor(color);
    for (auto& point : snake)
    {
        point.PrintCircular();
    }
}

void Snake::Move()//������
{
    switch (direction)
    {
    case Direction::UP:
        snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
        break;
    case Direction::DOWN:
        snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
        break;
    case Direction::LEFT:
        snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
        break;
    case Direction::RIGHT:
        snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
        break;
    default:
        break;
    }
    SetColor(color);
    snake.back().PrintCircular();
}

void Snake::NormalMove()//�������ƶ���β���̣��������ʹ��
{
    snake.front().Clear();
    snake.pop_front();
}

void Snake::Death(Snake& B, Map& map)
{
    if (!IfAlive(B, map))
    {
        Point* head = new Point(snake.back().GetX(), snake.back().GetY());
        for (auto& point : snake)
        {
            point.Clear();
        }

        if (!OverEdge(map))
        {
            SetColor(1);
            head->Print();
        }
        else if (!HitAnother(B))
        {
            SetColor(B.color);
            head->PrintCircular();
        }
        delete head;
    }
}

bool Snake::OverEdge(Map& map)  // �����߽�
{
    bool flag = true;
    Point* head_A = new Point(snake.back().GetX(), snake.back().GetY());  // ���ͷ������
    for (auto& point : map.initmap)
    {
        if (point == *head_A) flag = false;
    }
    delete head_A;
    return flag;
}

bool Snake::HitItself()  // ײ������
{
    std::deque<Point>::size_type cnt = 1;
    Point *head = new Point(snake.back().GetX(), snake.back().GetY());  // ���ͷ������
    for (auto& point : snake)  // ���������������ͷ����ͬ�����겻�����߳�������ζ����ͷ��ײ������
    {
        if (!(point == *head))  // ���в����ڷ���û���������أ����е���ȡ��
        {
            ++cnt;
        }
        else
        {
            break;
        }
    }
    delete head;
    if (cnt == snake.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Snake::HitAnother(Snake& B)  // ײ����һֻ��
{
    bool flag = true;
    Point* head_A = new Point(snake.back().GetX(), snake.back().GetY());  // ���ͷ������
    for (auto& point : B.snake) 
    {
        if (point == *head_A) flag = false;
    }
    delete head_A;
    return flag;
}

bool Snake::IfAlive(Snake& B, Map& map)
{
    if (color != B.color) 
    {
        return OverEdge(map) && HitItself() && HitAnother(B);
    }
    else 
    {
        return OverEdge(map) && HitItself();
    }

}

bool Snake::ChangeDirection(Snake& A, Snake& B)//�ı䷽��
{
    char ch;
    if (_kbhit())//kbhit��������ֵΪ��������ע��
    {
        ch = _getch();
        switch (ch)
        {
        case -32:
            ch = _getch();
            switch (ch)
            {            
            case 72:
                if (A.direction != Direction::DOWN && A.color == 6)  // ��������뵱ǰ�˶������෴����Ч����ֻ�ܿ��ƻ���
                {
                    A.direction = Direction::UP;
                }
                break;
            case 80:
                if (A.direction != Direction::UP && A.color == 6)
                {
                    A.direction = Direction::DOWN;
                }
                break;
            case 75:
                if (A.direction != Direction::RIGHT && A.color == 6)
                {
                    A.direction = Direction::LEFT;
                }
                break;
            case 77:
                if (A.direction != Direction::LEFT && A.color == 6)
                {
                    A.direction = Direction::RIGHT;
                }
                break;
            default:
                break;
            }
            return true;
        
        case 119:
            if (B.direction != Direction::DOWN && B.color == 4)//��������뵱ǰ�˶������෴����Ч����ֻ�ܿ��ƺ���
            {
                B.direction = Direction::UP;
            }
            return true;
        case 115:
            if (B.direction != Direction::UP && B.color == 4)
            {
                B.direction = Direction::DOWN;
            }
            return true;
        case 97:
            if (B.direction != Direction::RIGHT && B.color == 4)
            {
                B.direction = Direction::LEFT;
            }
            return true;
        case 100:
            if (B.direction != Direction::LEFT && B.color == 4)
            {
                B.direction = Direction::RIGHT;
            }
            return true;

        case 27://ESC
            return false;

        default:
            return true;
        }
    }
    return true;
}

bool Snake::GetFood(const Food& cfood)
{
    if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Snake::GetBigFood(Food& cfood)
{
    if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
    {
        cfood.big_flag = false;
        cfood.big_x = 0;
        cfood.big_y = 0;
        SetCursorPosition(1, 0);
        std::cout << "                                                            " ;
        return true;
    }
    else
    {
        return false;
    }
}