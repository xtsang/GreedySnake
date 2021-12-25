#ifndef MAP_H
#define MAP_H

#include "point.h"
#include <vector>

class Map {
friend class Food;
friend class Snake;
friend void Machine(Snake&, Snake&, Food&, Map&);
public:
    Map(int);  // 默认构造函数，将正方形各点压入initmap
    void PrintInitmap();  // 绘制初始地图
private:
    std::vector<Point> initmap;  // 保存初始地图
    /* 
    Map类可自定义多种地图，只需将表示地图的各个点保存在相应的map中，并在Snake类中增加相应判断撞墙函数即可
    std::vector<Point> map1;
    std::vector<Point> map2;
    */
};

#endif  // MAP_H
