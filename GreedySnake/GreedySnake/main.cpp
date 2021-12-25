#include "controller.h"
int main()  // 程序入口
{
    Start();  // 开始界面
    // 游戏一级循环可视为一个死循环，直到退出游戏时循环结束 
    while (true)  
    {          
        Select();  // 选择界面
        DrawGame();  // 绘制游戏界面    
        // 开启游戏二级循环，当重新开始或退出游戏时，结束循环并返回值给tmp
        int tmp = PlayGame();  
        if (tmp == 1)  // 返回值为1时重新开始游戏 
        {            
            ReStart();  // 重新开始界面
            continue;
        }
        else if (tmp == 2)  // 返回值为2时退出游戏
        {             
            break;
        } 
        else 
        {
            break;
        }
    }    
    return 0;
}
