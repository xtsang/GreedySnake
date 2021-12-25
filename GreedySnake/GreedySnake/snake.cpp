#include "snake.h"
#include <conio.h>
#include "tools.h"
#include <iostream>
#include "map.h"

void Snake::InitSnake()  // 初始化蛇
{
    SetColor(color);
    for (auto& point : snake)
    {
        point.PrintCircular();
    }
}

void Snake::Move()//蛇增长
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

void Snake::NormalMove()//蛇正常移动，尾缩短，配合增长使用
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

bool Snake::OverEdge(Map& map)  // 超出边界
{
    bool flag = true;
    Point* head_A = new Point(snake.back().GetX(), snake.back().GetY());  // 获得头部坐标
    for (auto& point : map.initmap)
    {
        if (point == *head_A) flag = false;
    }
    delete head_A;
    return flag;
}

bool Snake::HitItself()  // 撞到自身
{
    std::deque<Point>::size_type cnt = 1;
    Point *head = new Point(snake.back().GetX(), snake.back().GetY());  // 获得头部坐标
    for (auto& point : snake)  // 如果整条蛇中与蛇头不相同的坐标不等于蛇长，则意味着蛇头碰撞到自身
    {
        if (!(point == *head))  // 类中不等于符号没有隐含重载，故判等再取反
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

bool Snake::HitAnother(Snake& B)  // 撞到另一只蛇
{
    bool flag = true;
    Point* head_A = new Point(snake.back().GetX(), snake.back().GetY());  // 获得头部坐标
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

bool Snake::ChangeDirection(Snake& A, Snake& B)//改变方向
{
    char ch;
    if (_kbhit())//kbhit函数返回值为两个，需注意
    {
        ch = _getch();
        switch (ch)
        {
        case -32:
            ch = _getch();
            switch (ch)
            {            
            case 72:
                if (A.direction != Direction::DOWN && A.color == 6)  // 如果方向与当前运动方向相反则无效，且只能控制黄蛇
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
            if (B.direction != Direction::DOWN && B.color == 4)//如果方向与当前运动方向相反则无效，且只能控制红蛇
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