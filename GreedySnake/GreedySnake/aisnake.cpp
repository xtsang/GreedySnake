#include "aisnake.h"
#include "snake.h"
#include "food.h"
#include "map.h"
#include "point.h"
#include <deque>

void Machine(Snake& A, Snake& B, Food& cfood, Map& map)
{
    // ������ͼ
    int ValueMap[31][31] = {0};  //0����δ̽����1�����ϰ��ǽ���ߣ���2������̽�����������������ϰ����3����ʳ�� 
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};  // ������������ 

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

    ValueMap[cfood.x][cfood.y] = 3;  // ���Ե�ʳ����ʳ�������غϣ����ȸ�ֵʳ��ٸ�ֵ����
    if (cfood.big_flag)  // ���ݵ÷��ж����ȳ��ĸ�ʳ��
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

    // ��ʼ����ȥʳ���·��
    std::deque<Node> aisnake;
    Node* NodeMap[31][31] = {NULL};
    
    Node* head = new Node{A.snake.back().GetX(), A.snake.back().GetY(), 0, NULL};  // ��ʼ��ͷ������
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

                    if (tmp->x - head->x == 1 && tmp->y - head->y == 0)  // ��
                    {
                        A.direction = Snake::Direction::RIGHT;
                        goto Delete;
                    }
                    else if (tmp->x - head->x == -1 && tmp->y - head->y == 0)  // ��
                    {
                        A.direction = Snake::Direction::LEFT;
                        goto Delete;
                    }
                    else if (tmp->x - head->x == 0 && tmp->y - head->y == -1)  // ��
                    {
                        A.direction = Snake::Direction::UP;
                        goto Delete;
                    }
                    else  // ��
                    {
                        A.direction = Snake::Direction::DOWN;
                        goto Delete;
                    }
                }
                ValueMap[next.x][next.y] = 2;  // ���ж����޸�
                aisnake.push_back(next);
            }
        }
    }

    // δ�ҵ�ʳ��·�������ȥ�Լ�β�͵�·��
    if (ValueMap[A.snake.front().GetX()][A.snake.front().GetY() + 1] == 2  // ��Ϊ������ʱ�򲻻ᾭ����β������ֻ���ж���β��Χ���ĸ�����û����̽���������ߣ��ĸ��� 
     || ValueMap[A.snake.front().GetX() + 1][A.snake.front().GetY()] == 2  // Ҳ������NodeMap��ΪNULL�ȽϽ����ж� 
     || ValueMap[A.snake.front().GetX()][A.snake.front().GetY() - 1] == 2 
     || ValueMap[A.snake.front().GetX() - 1][A.snake.front().GetY()] == 2)  
    {
        Node* tmp = head;  // ��ʼ��step=0�����ں���Ƚ�

        // Ѱ��ȥβ�����·��
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

        if (tmp->x - head->x == 1 && tmp->y - head->y == 0)  // ��
        {
            A.direction = Snake::Direction::RIGHT;
            goto Delete;
        }
        else if (tmp->x - head->x == -1 && tmp->y - head->y == 0)  // ��
        {
            A.direction = Snake::Direction::LEFT;
            goto Delete;
        }
        else if (tmp->x - head->x == 0 && tmp->y - head->y == -1)  // ��
        {
            A.direction = Snake::Direction::UP;
            goto Delete;
        }
        else  // ��
        {
            A.direction = Snake::Direction::DOWN;
            goto Delete;
        }
    }
                      
    // ��δ�ҵ������ѡȡ����
    if (ValueMap[A.snake.back().GetX() + 1][A.snake.back().GetY()] == 2)  // ��
    {
        A.direction = Snake::Direction::RIGHT;
        goto Delete;
    }
    else if (ValueMap[A.snake.back().GetX() - 1][A.snake.back().GetY()] == 2)  // ��
    {
        A.direction = Snake::Direction::LEFT;
        goto Delete;
    }
    else if (ValueMap[A.snake.back().GetX()][A.snake.back().GetY() - 1] == 2)  // ��
    {
        A.direction = Snake::Direction::UP;
        goto Delete;
    }
    else if (ValueMap[A.snake.back().GetX()][A.snake.back().GetY() + 1] == 2)  // ��
    {
        A.direction = Snake::Direction::DOWN;
        goto Delete;
    }

    // �ͷ�����Ŀռ�
Delete:
    for (int i = 2; i <= 29; ++i)
    {
        for (int j = 2; j <= 29; ++j)
        {
            if (NodeMap[i][j] != NULL) delete NodeMap[i][j];
        }
    }
}

