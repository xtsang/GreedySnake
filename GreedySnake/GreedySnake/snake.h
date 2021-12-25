#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"

class Food;
class Snake {
friend class Food;  // ��Food����Ϊ��Ԫ���Ա������˽��Ԫ��
friend void Machine(Snake&, Snake&, Food&, Map&);
public:
    enum class Direction {UP, DOWN, LEFT, RIGHT};

    Snake(int post_x = 22, int colorid = 6) 
    {
        snake.emplace_back(post_x, 4);
        snake.emplace_back(post_x, 5);
        snake.emplace_back(post_x, 6);
        direction = Direction::DOWN;
        color = colorid;
    }

    void InitSnake();
    void Move();
    void NormalMove();
    void Death(Snake&, Map&);
    bool OverEdge(Map&);
    bool HitItself();
    bool HitAnother(Snake&);
    bool IfAlive(Snake&, Map&);
    static bool ChangeDirection(Snake&, Snake&);
    bool GetFood(const Food&);
    bool GetBigFood(Food&); 
private:
    std::deque<Point> snake;
    Direction direction;
    int color; 
};

#endif // SNAKE_H
