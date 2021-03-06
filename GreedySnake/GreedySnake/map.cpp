#include "map.h"
#include <time.h>
#include <windows.h>

Map::Map(int mapnum)  // 默认构造函数，将正方形各点压入initmap
{
    initmap.emplace_back(Point(1, 1));
    initmap.emplace_back(Point(2, 1));
    initmap.emplace_back(Point(3, 1));
    initmap.emplace_back(Point(4, 1));
    initmap.emplace_back(Point(5, 1));
    initmap.emplace_back(Point(6, 1));
    initmap.emplace_back(Point(7, 1));
    initmap.emplace_back(Point(8, 1));
    initmap.emplace_back(Point(9, 1));
    initmap.emplace_back(Point(10, 1));
    initmap.emplace_back(Point(11, 1));
    initmap.emplace_back(Point(12, 1));
    initmap.emplace_back(Point(13, 1));
    initmap.emplace_back(Point(14, 1));
    initmap.emplace_back(Point(15, 1));
    initmap.emplace_back(Point(16, 1));
    initmap.emplace_back(Point(17, 1));
    initmap.emplace_back(Point(18, 1));
    initmap.emplace_back(Point(19, 1));
    initmap.emplace_back(Point(20, 1));
    initmap.emplace_back(Point(21, 1));
    initmap.emplace_back(Point(22, 1));
    initmap.emplace_back(Point(23, 1));
    initmap.emplace_back(Point(24, 1));
    initmap.emplace_back(Point(25, 1));
    initmap.emplace_back(Point(26, 1));
    initmap.emplace_back(Point(27, 1));
    initmap.emplace_back(Point(28, 1));
    initmap.emplace_back(Point(29, 1));
    initmap.emplace_back(Point(30, 1));
    initmap.emplace_back(Point(1, 2));
    initmap.emplace_back(Point(30, 2));
    initmap.emplace_back(Point(1, 3));
    initmap.emplace_back(Point(30, 3));
    initmap.emplace_back(Point(1, 4));
    initmap.emplace_back(Point(30, 4));
    initmap.emplace_back(Point(1, 5));
    initmap.emplace_back(Point(30, 5));
    initmap.emplace_back(Point(1, 6));
    initmap.emplace_back(Point(30, 6));
    initmap.emplace_back(Point(1, 7));
    initmap.emplace_back(Point(30, 7));
    initmap.emplace_back(Point(1, 8));
    initmap.emplace_back(Point(30, 8));
    initmap.emplace_back(Point(1, 9));
    initmap.emplace_back(Point(30, 9));
    initmap.emplace_back(Point(1, 10));
    initmap.emplace_back(Point(30, 10));
    initmap.emplace_back(Point(1, 11));
    initmap.emplace_back(Point(30, 11));
    initmap.emplace_back(Point(1, 12));
    initmap.emplace_back(Point(30, 12));
    initmap.emplace_back(Point(1, 13));
    initmap.emplace_back(Point(30, 13));
    initmap.emplace_back(Point(1, 14));
    initmap.emplace_back(Point(30, 14));
    initmap.emplace_back(Point(1, 15));
    initmap.emplace_back(Point(30, 15));
    initmap.emplace_back(Point(1, 16));
    initmap.emplace_back(Point(30, 16));
    initmap.emplace_back(Point(1, 17));
    initmap.emplace_back(Point(30, 17));
    initmap.emplace_back(Point(1, 18));
    initmap.emplace_back(Point(30, 18));
    initmap.emplace_back(Point(1, 19));
    initmap.emplace_back(Point(30, 19));
    initmap.emplace_back(Point(1, 20));
    initmap.emplace_back(Point(30, 20));
    initmap.emplace_back(Point(1, 21));
    initmap.emplace_back(Point(30, 21));
    initmap.emplace_back(Point(1, 22));
    initmap.emplace_back(Point(30, 22));
    initmap.emplace_back(Point(1, 23));
    initmap.emplace_back(Point(30, 23));
    initmap.emplace_back(Point(1, 24));
    initmap.emplace_back(Point(30, 24));
    initmap.emplace_back(Point(1, 25));
    initmap.emplace_back(Point(30, 25));
    initmap.emplace_back(Point(1, 26));
    initmap.emplace_back(Point(30, 26));
    initmap.emplace_back(Point(1, 27));
    initmap.emplace_back(Point(30, 27));
    initmap.emplace_back(Point(1, 28));
    initmap.emplace_back(Point(30, 28));
    initmap.emplace_back(Point(1, 29));
    initmap.emplace_back(Point(30, 29));
    initmap.emplace_back(Point(1, 30));
    initmap.emplace_back(Point(2, 30));
    initmap.emplace_back(Point(3, 30));
    initmap.emplace_back(Point(4, 30));
    initmap.emplace_back(Point(5, 30));
    initmap.emplace_back(Point(6, 30));
    initmap.emplace_back(Point(7, 30));
    initmap.emplace_back(Point(8, 30));
    initmap.emplace_back(Point(9, 30));
    initmap.emplace_back(Point(10, 30));
    initmap.emplace_back(Point(11, 30));
    initmap.emplace_back(Point(12, 30));
    initmap.emplace_back(Point(13, 30));
    initmap.emplace_back(Point(14, 30));
    initmap.emplace_back(Point(15, 30));
    initmap.emplace_back(Point(16, 30));
    initmap.emplace_back(Point(17, 30));
    initmap.emplace_back(Point(18, 30));
    initmap.emplace_back(Point(19, 30));
    initmap.emplace_back(Point(20, 30));
    initmap.emplace_back(Point(21, 30));
    initmap.emplace_back(Point(22, 30));
    initmap.emplace_back(Point(23, 30));
    initmap.emplace_back(Point(24, 30));
    initmap.emplace_back(Point(25, 30));
    initmap.emplace_back(Point(26, 30));
    initmap.emplace_back(Point(27, 30));
    initmap.emplace_back(Point(28, 30));
    initmap.emplace_back(Point(29, 30));
    initmap.emplace_back(Point(30, 30));
    int num = mapnum % 28;
    if (num == 6 || num == 7 || num == 8) {
        initmap.emplace_back(Point(14, 14));
        initmap.emplace_back(Point(14, 15));
        initmap.emplace_back(Point(14, 16));
        initmap.emplace_back(Point(14, 17));
        initmap.emplace_back(Point(15, 14));
        initmap.emplace_back(Point(15, 15));
        initmap.emplace_back(Point(15, 16));
        initmap.emplace_back(Point(15, 17));
        initmap.emplace_back(Point(16, 14));
        initmap.emplace_back(Point(16, 15));
        initmap.emplace_back(Point(16, 16));
        initmap.emplace_back(Point(16, 17));
        initmap.emplace_back(Point(17, 14));
        initmap.emplace_back(Point(17, 15));
        initmap.emplace_back(Point(17, 16));
        initmap.emplace_back(Point(17, 17));
    }
    else if (num == 9 || num == 10 || num == 11) {
        initmap.emplace_back(Point(2, 2));
        initmap.emplace_back(Point(3, 2));
        initmap.emplace_back(Point(28, 2));
        initmap.emplace_back(Point(29, 2));
        initmap.emplace_back(Point(2, 3));
        //initmap.emplace_back(Point(3, 3));
        //initmap.emplace_back(Point(28, 3));
        initmap.emplace_back(Point(29, 3));
        initmap.emplace_back(Point(4, 4));
        initmap.emplace_back(Point(5, 4));
        initmap.emplace_back(Point(26, 4));
        initmap.emplace_back(Point(27, 4));
        initmap.emplace_back(Point(4, 5));
        initmap.emplace_back(Point(5, 5));
        initmap.emplace_back(Point(6, 5));
        initmap.emplace_back(Point(25, 5));
        initmap.emplace_back(Point(26, 5));
        initmap.emplace_back(Point(27, 5));
        initmap.emplace_back(Point(5, 6));
        initmap.emplace_back(Point(6, 6));
        initmap.emplace_back(Point(7, 6));
        initmap.emplace_back(Point(24, 6));
        initmap.emplace_back(Point(25, 6));
        initmap.emplace_back(Point(26, 6));
        initmap.emplace_back(Point(6, 7));
        initmap.emplace_back(Point(7, 7));
        initmap.emplace_back(Point(24, 7));
        initmap.emplace_back(Point(25, 7));
        initmap.emplace_back(Point(8, 8));
        initmap.emplace_back(Point(23, 8));
        initmap.emplace_back(Point(8, 23));
        initmap.emplace_back(Point(23, 23));
        initmap.emplace_back(Point(6, 24));
        initmap.emplace_back(Point(7, 24));
        initmap.emplace_back(Point(24, 24));
        initmap.emplace_back(Point(25, 24));
        initmap.emplace_back(Point(5, 25));
        initmap.emplace_back(Point(6, 25));
        initmap.emplace_back(Point(7, 25));
        initmap.emplace_back(Point(24, 25));
        initmap.emplace_back(Point(25, 25));
        initmap.emplace_back(Point(26, 25));
        initmap.emplace_back(Point(4, 26));
        initmap.emplace_back(Point(5, 26));
        initmap.emplace_back(Point(6, 26));
        initmap.emplace_back(Point(25, 26));
        initmap.emplace_back(Point(26, 26));
        initmap.emplace_back(Point(27, 26));
        initmap.emplace_back(Point(4, 27));
        initmap.emplace_back(Point(5, 27));
        initmap.emplace_back(Point(26, 27));
        initmap.emplace_back(Point(27, 27));
        initmap.emplace_back(Point(2, 28));
        //initmap.emplace_back(Point(3, 28));
        //initmap.emplace_back(Point(28, 28));
        initmap.emplace_back(Point(29, 28));
        initmap.emplace_back(Point(2, 29));
        initmap.emplace_back(Point(3, 29));
        initmap.emplace_back(Point(28, 29));
        initmap.emplace_back(Point(29, 29));
    }
    else if (num == 12 || num == 13 || num == 14) {
        initmap.emplace_back(Point(4, 4));
        initmap.emplace_back(Point(5, 4));
        initmap.emplace_back(Point(6, 4));
        initmap.emplace_back(Point(7, 4));
        initmap.emplace_back(Point(24, 4));
        initmap.emplace_back(Point(25, 4));
        initmap.emplace_back(Point(26, 4));
        initmap.emplace_back(Point(27, 4));
        initmap.emplace_back(Point(4, 5));
        initmap.emplace_back(Point(27, 5));
        initmap.emplace_back(Point(4, 6));
        initmap.emplace_back(Point(27, 6));
        initmap.emplace_back(Point(4, 7));
        initmap.emplace_back(Point(27, 7));
        initmap.emplace_back(Point(15, 13));
        initmap.emplace_back(Point(16, 13));
        initmap.emplace_back(Point(15, 14));
        initmap.emplace_back(Point(16, 14));
        initmap.emplace_back(Point(13, 15));
        initmap.emplace_back(Point(14, 15));
        initmap.emplace_back(Point(15, 15));
        initmap.emplace_back(Point(16, 15));
        initmap.emplace_back(Point(17, 15));
        initmap.emplace_back(Point(18, 15));
        initmap.emplace_back(Point(13, 16));
        initmap.emplace_back(Point(14, 16));
        initmap.emplace_back(Point(15, 16));
        initmap.emplace_back(Point(16, 16));
        initmap.emplace_back(Point(17, 16));
        initmap.emplace_back(Point(18, 16));
        initmap.emplace_back(Point(15, 17));
        initmap.emplace_back(Point(16, 17));
        initmap.emplace_back(Point(15, 18));
        initmap.emplace_back(Point(16, 18));
        initmap.emplace_back(Point(4, 24));
        initmap.emplace_back(Point(27, 24));
        initmap.emplace_back(Point(4, 25));
        initmap.emplace_back(Point(27, 25));
        initmap.emplace_back(Point(4, 26));
        initmap.emplace_back(Point(27, 26));
        initmap.emplace_back(Point(4, 27));
        initmap.emplace_back(Point(5, 27));
        initmap.emplace_back(Point(6, 27));
        initmap.emplace_back(Point(7, 27));
        initmap.emplace_back(Point(24, 27));
        initmap.emplace_back(Point(25, 27));
        initmap.emplace_back(Point(26, 27));
        initmap.emplace_back(Point(27, 27));
    }
    else if (num == 15 || num == 16 || num == 17) {
        initmap.emplace_back(Point(12, 2));
        initmap.emplace_back(Point(12, 3));
        initmap.emplace_back(Point(12, 4));
        initmap.emplace_back(Point(12, 5));
        initmap.emplace_back(Point(12, 6));
        initmap.emplace_back(Point(2, 12));
        initmap.emplace_back(Point(3, 12));
        initmap.emplace_back(Point(4, 12));
        initmap.emplace_back(Point(5, 12));
        initmap.emplace_back(Point(6, 12));
        initmap.emplace_back(Point(18, 2));
        initmap.emplace_back(Point(18, 3));
        initmap.emplace_back(Point(18, 4));
        initmap.emplace_back(Point(18, 5));
        initmap.emplace_back(Point(18, 6));
        initmap.emplace_back(Point(28, 12));
        initmap.emplace_back(Point(27, 12));
        initmap.emplace_back(Point(26, 12));
        initmap.emplace_back(Point(25, 12));
        initmap.emplace_back(Point(29, 12));
        initmap.emplace_back(Point(2, 18));
        initmap.emplace_back(Point(3, 18));
        initmap.emplace_back(Point(4, 18));
        initmap.emplace_back(Point(5, 18));
        initmap.emplace_back(Point(6, 18));
        initmap.emplace_back(Point(12, 28));
        initmap.emplace_back(Point(12, 27));
        initmap.emplace_back(Point(12, 26));
        initmap.emplace_back(Point(12, 25));
        initmap.emplace_back(Point(12, 29));
        initmap.emplace_back(Point(18, 28));
        initmap.emplace_back(Point(18, 27));
        initmap.emplace_back(Point(18, 26));
        initmap.emplace_back(Point(18, 25));
        initmap.emplace_back(Point(18, 29));
        initmap.emplace_back(Point(28, 18));
        initmap.emplace_back(Point(27, 18));
        initmap.emplace_back(Point(26, 18));
        initmap.emplace_back(Point(25, 18));
        initmap.emplace_back(Point(29, 18));
    }
    else if (num == 18 || num == 19 || num == 20) {
    initmap.emplace_back(Point(5, 8)); 
    initmap.emplace_back(Point(6, 8)); 
    initmap.emplace_back(Point(7, 8)); 
    initmap.emplace_back(Point(5, 9)); 
    initmap.emplace_back(Point(6, 9)); 
    initmap.emplace_back(Point(7, 9)); 
    initmap.emplace_back(Point(14, 8)); 
    initmap.emplace_back(Point(15, 8)); 
    initmap.emplace_back(Point(14, 9)); 
    initmap.emplace_back(Point(15, 9)); 
    initmap.emplace_back(Point(25, 8)); 
    initmap.emplace_back(Point(24, 8)); 
    initmap.emplace_back(Point(23, 8)); 
    initmap.emplace_back(Point(25, 9)); 
    initmap.emplace_back(Point(24, 9)); 
    initmap.emplace_back(Point(23, 9)); 
    initmap.emplace_back(Point(16, 8)); 
    initmap.emplace_back(Point(15, 8)); 
    initmap.emplace_back(Point(16, 9)); 
    initmap.emplace_back(Point(15, 9)); 
    initmap.emplace_back(Point(5, 22)); 
    initmap.emplace_back(Point(6, 22)); 
    initmap.emplace_back(Point(7, 22)); 
    initmap.emplace_back(Point(5, 21)); 
    initmap.emplace_back(Point(6, 21)); 
    initmap.emplace_back(Point(7, 21)); 
    initmap.emplace_back(Point(14, 22)); 
    initmap.emplace_back(Point(15, 22)); 
    initmap.emplace_back(Point(14, 21)); 
    initmap.emplace_back(Point(15, 21)); 
    initmap.emplace_back(Point(25, 22)); 
    initmap.emplace_back(Point(24, 22)); 
    initmap.emplace_back(Point(23, 22)); 
    initmap.emplace_back(Point(25, 21)); 
    initmap.emplace_back(Point(24, 21)); 
    initmap.emplace_back(Point(23, 21)); 
    initmap.emplace_back(Point(16, 22)); 
    initmap.emplace_back(Point(15, 22)); 
    initmap.emplace_back(Point(16, 21)); 
    initmap.emplace_back(Point(15, 21));
    }
    else if (num == 21 || num == 22 || num == 23) {
    initmap.emplace_back(Point(7, 7));
    initmap.emplace_back(Point(7, 8));
    initmap.emplace_back(Point(7, 10));
    initmap.emplace_back(Point(7, 11));
    initmap.emplace_back(Point(7, 12));
    initmap.emplace_back(Point(8, 7));
    initmap.emplace_back(Point(10, 7));
    initmap.emplace_back(Point(11, 7));
    initmap.emplace_back(Point(12, 7));
    initmap.emplace_back(Point(8, 24));
    initmap.emplace_back(Point(10, 24));
    initmap.emplace_back(Point(11, 24));
    initmap.emplace_back(Point(12, 24));
    initmap.emplace_back(Point(24, 8));
    initmap.emplace_back(Point(24, 10));
    initmap.emplace_back(Point(24, 11));
    initmap.emplace_back(Point(24, 12));
    initmap.emplace_back(Point(7, 19));
    initmap.emplace_back(Point(7, 20));
    initmap.emplace_back(Point(7, 21));
    initmap.emplace_back(Point(7, 23));
    initmap.emplace_back(Point(7, 24));
    initmap.emplace_back(Point(24, 7));
    initmap.emplace_back(Point(23, 7));
    initmap.emplace_back(Point(21, 7));
    initmap.emplace_back(Point(20, 7));
    initmap.emplace_back(Point(19, 7));
    initmap.emplace_back(Point(24, 24));
    initmap.emplace_back(Point(23, 24));
    initmap.emplace_back(Point(21, 24));
    initmap.emplace_back(Point(20, 24));
    initmap.emplace_back(Point(19, 24));
    initmap.emplace_back(Point(24, 19));
    initmap.emplace_back(Point(24, 20));
    initmap.emplace_back(Point(24, 21));
    initmap.emplace_back(Point(24, 22));
    initmap.emplace_back(Point(24, 23));

}
    else if (num == 24 || num == 25 || num == 26) {
    initmap.emplace_back(Point(5, 6)); 
    initmap.emplace_back(Point(5, 7)); 
    initmap.emplace_back(Point(6, 7)); 
    initmap.emplace_back(Point(6, 6)); 
    initmap.emplace_back(Point(13, 6)); 
    initmap.emplace_back(Point(13, 7)); 
    initmap.emplace_back(Point(12, 6)); 
    initmap.emplace_back(Point(12, 7)); 
    initmap.emplace_back(Point(5, 15)); 
    initmap.emplace_back(Point(6, 15));  
    initmap.emplace_back(Point(25, 6)); 
    initmap.emplace_back(Point(25, 7));
    initmap.emplace_back(Point(24, 7)); 
    initmap.emplace_back(Point(24, 6)); 
    initmap.emplace_back(Point(17, 7)); 
    initmap.emplace_back(Point(17, 6)); 
    initmap.emplace_back(Point(18, 7)); 
    initmap.emplace_back(Point(18, 6)); 
    initmap.emplace_back(Point(25, 15)); 
    initmap.emplace_back(Point(24, 15));  
    initmap.emplace_back(Point(5, 24));
    initmap.emplace_back(Point(5, 25)); 
    initmap.emplace_back(Point(6, 25)); 
    initmap.emplace_back(Point(6, 24)); 
    initmap.emplace_back(Point(13, 24)); 
    initmap.emplace_back(Point(13, 25)); 
    initmap.emplace_back(Point(12, 24));
    initmap.emplace_back(Point(12, 25)); 
    initmap.emplace_back(Point(5, 15)); 
    initmap.emplace_back(Point(5, 16));
    initmap.emplace_back(Point(6, 15)); 
    initmap.emplace_back(Point(6, 16)); 
    initmap.emplace_back(Point(25, 24));
    initmap.emplace_back(Point(25, 25)); 
    initmap.emplace_back(Point(24, 25)); 
    initmap.emplace_back(Point(24, 24));
    initmap.emplace_back(Point(17, 24)); 
    initmap.emplace_back(Point(17, 25)); 
    initmap.emplace_back(Point(18, 24)); 
    initmap.emplace_back(Point(18, 25)); 
    initmap.emplace_back(Point(25, 15)); 
    initmap.emplace_back(Point(24, 15));
    initmap.emplace_back(Point(25, 16)); 
    initmap.emplace_back(Point(24, 16));
    } 
    else if (num == 27) {
        initmap.emplace_back(Point(12, 2));
        initmap.emplace_back(Point(19, 2));
        initmap.emplace_back(Point(12, 3));
        initmap.emplace_back(Point(19, 3));
        initmap.emplace_back(Point(19, 4));
        initmap.emplace_back(Point(19, 5));
        initmap.emplace_back(Point(19, 6));
        initmap.emplace_back(Point(7, 7));
        initmap.emplace_back(Point(12, 7));
        initmap.emplace_back(Point(16, 7));
        initmap.emplace_back(Point(19, 7));
        initmap.emplace_back(Point(24, 7));
        initmap.emplace_back(Point(12, 8));
        initmap.emplace_back(Point(16, 8));
        initmap.emplace_back(Point(19, 8));
        initmap.emplace_back(Point(12, 9));
        initmap.emplace_back(Point(16, 9));
        initmap.emplace_back(Point(19, 9));
        initmap.emplace_back(Point(12, 10));
        initmap.emplace_back(Point(12, 11));
        initmap.emplace_back(Point(12, 12));
        initmap.emplace_back(Point(2, 13));
        initmap.emplace_back(Point(3, 13));
        initmap.emplace_back(Point(4, 13));
        initmap.emplace_back(Point(5, 13));
        initmap.emplace_back(Point(6, 13));
        initmap.emplace_back(Point(7, 13));
        initmap.emplace_back(Point(8, 13));
        initmap.emplace_back(Point(20, 13));
        initmap.emplace_back(Point(21, 13));
        initmap.emplace_back(Point(22, 13));
        initmap.emplace_back(Point(23, 13));
        initmap.emplace_back(Point(24, 13));
        initmap.emplace_back(Point(28, 13));
        initmap.emplace_back(Point(29, 13));
        initmap.emplace_back(Point(15, 14));
        initmap.emplace_back(Point(16, 14));
        initmap.emplace_back(Point(15, 17));
        initmap.emplace_back(Point(16, 17));
        initmap.emplace_back(Point(2, 18));
        initmap.emplace_back(Point(3, 18));
        initmap.emplace_back(Point(4, 18));
        initmap.emplace_back(Point(8, 18));
        initmap.emplace_back(Point(9, 18));
        initmap.emplace_back(Point(10, 18));
        initmap.emplace_back(Point(11, 18));
        initmap.emplace_back(Point(23, 18));
        initmap.emplace_back(Point(24, 18));
        initmap.emplace_back(Point(25, 18));
        initmap.emplace_back(Point(26, 18));
        initmap.emplace_back(Point(27, 18));
        initmap.emplace_back(Point(28, 18));
        initmap.emplace_back(Point(29, 18));
        initmap.emplace_back(Point(19, 19));
        initmap.emplace_back(Point(19, 20));
        initmap.emplace_back(Point(19, 21));
        initmap.emplace_back(Point(12, 22));
        initmap.emplace_back(Point(15, 22));
        initmap.emplace_back(Point(19, 22));
        initmap.emplace_back(Point(12, 23));
        initmap.emplace_back(Point(15, 23));
        initmap.emplace_back(Point(19, 23));
        initmap.emplace_back(Point(7, 24));
        initmap.emplace_back(Point(12, 24));
        initmap.emplace_back(Point(15, 24));
        initmap.emplace_back(Point(19, 24));
        initmap.emplace_back(Point(24, 24));
        initmap.emplace_back(Point(12, 25));
        initmap.emplace_back(Point(12, 26));
        initmap.emplace_back(Point(12, 27));
        initmap.emplace_back(Point(12, 28));
        initmap.emplace_back(Point(19, 28));
        initmap.emplace_back(Point(12, 29));
        initmap.emplace_back(Point(19, 29));

    }
}

void Map::PrintInitmap()//绘制初始地图
{
    for (auto& point : initmap)
    {
        point.Print();
        Sleep(10);//调用Sleep函数可营造动画效果
    }
}
