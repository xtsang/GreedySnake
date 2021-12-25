#include "aisnake.h"
#include "snake.h"
#include "food.h"
#include "map.h"
#include "point.h"
#include <deque>

void Machine(Snake& A, Snake& B, Food& cfood, Map& map)
{
    // 构建地图
    int ValueMap[31][31] = {0};  //0代表未探索，1代表障碍物（墙或蛇），2代表已探索（隐含意义是无障碍物），3代表食物 
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};  // 方向：右左上下 

    for (int i = 1; i <= 30; ++i)
    {
        for (int j = 1; j <= 30; ++j)
        {
            for (auto& point : map.initmap)
            {
                if (point.GetX() == i && point.GetY() == j) ValueMap[i][j] = 1;
            }
        }
    }

    ValueMap[cfood.x][cfood.y] = 3;  // 若吃到食物则食物与蛇重合，故先赋值食物，再赋值蛇身
    if (cfood.big_flag)  // 根据得分判断优先吃哪个食物
    {
        if ((cfood.GetProgressBar() - abs(A.snake.back().GetX()-cfood.big_x) - abs(A.snake.back().GetY()-cfood.big_y)) > 9)
        {
            ValueMap[cfood.big_x][cfood.big_y] = 3;
        }
    }

    for (auto& point : A.snake)
    { 
        ValueMap[point.GetX()][point.GetY()] = 1;
    }
    for (auto& point : B.snake)
    {
        ValueMap[point.GetX()][point.GetY()] = 1;
    }

    // 开始查找去食物的路径
    std::deque<Node> aisnake;
    Node* NodeMap[31][31] = {NULL};
    
    Node* head = new Node{A.snake.back().GetX(), A.snake.back().GetY(), 0, NULL};  // 初始化头部数据
    aisnake.push_back(*head);
    NodeMap[head->x][head->y] = head;
 
    while (!aisnake.empty()) 
    { 
        Node now, next; 
        now = aisnake.front();
        aisnake.pop_front();
        for (int i = 0; i < 4; i++)
        {
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1]; 
            if (ValueMap[next.x][next.y] != 1 && ValueMap[next.x][next.y] != 2)
            {
                next.step = now.step + 1;                                                      
                next.last = NodeMap[now.x][now.y];
                Node* tmp = new Node;
                memcpy(tmp, &next, sizeof(Node));
                NodeMap[next.x][next.y] = tmp;
                if (ValueMap[next.x][next.y] == 3)
                {
                    while (tmp->last != head)
                    {    
                        tmp = tmp->last;
                    }

                    if (tmp->x - head->x == 1 && tmp->y - head->y == 0)  // 右
                    {
                        A.direction = Snake::Direction::RIGHT;
                        goto Delete;
                    }
                    else if (tmp->x - head->x == -1 && tmp->y - head->y == 0)  // 左
                    {
                        A.direction = Snake::Direction::LEFT;
                        goto Delete;
                    }
                    else if (tmp->x - head->x == 0 && tmp->y - head->y == -1)  // 上
                    {
                        A.direction = Snake::Direction::UP;
                        goto Delete;
                    }
                    else  // 下
                    {
                        A.direction = Snake::Direction::DOWN;
                        goto Delete;
                    }
                }
                ValueMap[next.x][next.y] = 2;  // 先判断再修改
                aisnake.push_back(next);
            }
        }
    }

    // 未找到食物路径便查找去自己尾巴的路径
    if (ValueMap[A.snake.front().GetX()][A.snake.front().GetY() + 1] == 2  // 因为搜索的时候不会经过蛇尾，所以只能判断蛇尾周围的四个点有没有已探索（可以走）的格子 
     || ValueMap[A.snake.front().GetX() + 1][A.snake.front().GetY()] == 2  // 也可以用NodeMap不为NULL比较进行判断 
     || ValueMap[A.snake.front().GetX()][A.snake.front().GetY() - 1] == 2 
     || ValueMap[A.snake.front().GetX() - 1][A.snake.front().GetY()] == 2)  
    {
        Node* tmp = head;  // 初始化step=0，便于后面比较

        // 寻找去尾巴最长的路径
        if (ValueMap[A.snake.front().GetX()][A.snake.front().GetY() + 1] == 2 && NodeMap[A.snake.front().GetX()][A.snake.front().GetY() + 1]->step > head->step)
        {
            tmp = NodeMap[A.snake.front().GetX()][A.snake.front().GetY() + 1];
        }
        if (ValueMap[A.snake.front().GetX() + 1][A.snake.front().GetY()] == 2 && NodeMap[A.snake.front().GetX() + 1][A.snake.front().GetY()]->step > head->step)
        {
            tmp = NodeMap[A.snake.front().GetX() + 1][A.snake.front().GetY()];
        }
        if (ValueMap[A.snake.front().GetX()][A.snake.front().GetY() - 1] == 2 && NodeMap[A.snake.front().GetX()][A.snake.front().GetY() - 1]->step > head->step)
        {
            tmp = NodeMap[A.snake.front().GetX()][A.snake.front().GetY() - 1];
        }
        if (ValueMap[A.snake.front().GetX() - 1][A.snake.front().GetY()] == 2 && NodeMap[A.snake.front().GetX() - 1][A.snake.front().GetY()]->step > head->step)
        {
            tmp = NodeMap[A.snake.front().GetX() - 1][A.snake.front().GetY()];
        }

        while (tmp->last != head)
        {
            tmp = tmp->last;
        }

        if (tmp->x - head->x == 1 && tmp->y - head->y == 0)  // 右
        {
            A.direction = Snake::Direction::RIGHT;
            goto Delete;
        }
        else if (tmp->x - head->x == -1 && tmp->y - head->y == 0)  // 左
        {
            A.direction = Snake::Direction::LEFT;
            goto Delete;
        }
        else if (tmp->x - head->x == 0 && tmp->y - head->y == -1)  // 上
        {
            A.direction = Snake::Direction::UP;
            goto Delete;
        }
        else  // 下
        {
            A.direction = Snake::Direction::DOWN;
            goto Delete;
        }
    }
                      
    // 都未找到便随机选取方向
    if (ValueMap[A.snake.back().GetX() + 1][A.snake.back().GetY()] == 2)  // 右
    {
        A.direction = Snake::Direction::RIGHT;
        goto Delete;
    }
    else if (ValueMap[A.snake.back().GetX() - 1][A.snake.back().GetY()] == 2)  // 左
    {
        A.direction = Snake::Direction::LEFT;
        goto Delete;
    }
    else if (ValueMap[A.snake.back().GetX()][A.snake.back().GetY() - 1] == 2)  // 上
    {
        A.direction = Snake::Direction::UP;
        goto Delete;
    }
    else if (ValueMap[A.snake.back().GetX()][A.snake.back().GetY() + 1] == 2)  // 下
    {
        A.direction = Snake::Direction::DOWN;
        goto Delete;
    }

    // 释放申请的空间
Delete:
    for (int i = 2; i <= 29; ++i)
    {
        for (int j = 2; j <= 29; ++j)
        {
            if (NodeMap[i][j] != NULL) delete NodeMap[i][j];
        }
    }
}

