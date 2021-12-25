#ifndef FOOD_H
#define FOOD_H

class Snake;
class Map;
class Food {
friend class Snake;
friend void Machine(Snake&, Snake&, Food&, Map&);
public:
    Food() : cnt(0), flash_flag(false), big_flag(false), x(0), y(0), big_x(0), big_y(0), progress_bar(0) {}
    void DrawFood(Snake&, Snake&, Map&);
    void DrawBigFood(Snake&, Snake&, Map&);
    int GetCnt();
    void FlashBigFood();
    bool GetBigFlag();
    int GetProgressBar();
private:
    int cnt;
    bool flash_flag;  // ��˸���
    bool big_flag;  // �Ƿ�����ʱʳ����
    int x, y;
    int big_x, big_y;
    int progress_bar;  // ��ʱʳ�������
};

#endif  // FOOD_H
