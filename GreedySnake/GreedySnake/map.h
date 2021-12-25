#ifndef MAP_H
#define MAP_H

#include "point.h"
#include <vector>

class Map {
friend class Food;
friend class Snake;
friend void Machine(Snake&, Snake&, Food&, Map&);
public:
    Map(int);  // Ĭ�Ϲ��캯�����������θ���ѹ��initmap
    void PrintInitmap();  // ���Ƴ�ʼ��ͼ
private:
    std::vector<Point> initmap;  // �����ʼ��ͼ
    /* 
    Map����Զ�����ֵ�ͼ��ֻ�轫��ʾ��ͼ�ĸ����㱣������Ӧ��map�У�����Snake����������Ӧ�ж�ײǽ��������
    std::vector<Point> map1;
    std::vector<Point> map2;
    */
};

#endif  // MAP_H
