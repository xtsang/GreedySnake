#ifndef STRATINTERFACE_H
#define STARTINTERFACE_H

#include <deque>
#include <vector>
#include "point.h"

class StartInterface
{
public:
	StartInterface(int speed) : speed(speed) {
		startsnake2.emplace_back(Point(40, 14));//蛇形2
		startsnake2.emplace_back(Point(0, 4));
		startsnake2.emplace_back(Point(39, 14));
		startsnake2.emplace_back(Point(1, 4));
		startsnake2.emplace_back(Point(38, 15));
		startsnake2.emplace_back(Point(2, 5));
		startsnake2.emplace_back(Point(37, 16));
		startsnake2.emplace_back(Point(3, 6));
		startsnake2.emplace_back(Point(36, 17));
		startsnake2.emplace_back(Point(4, 7));
		startsnake2.emplace_back(Point(35, 18));
		startsnake2.emplace_back(Point(5, 8));
		startsnake2.emplace_back(Point(34, 17));
		startsnake2.emplace_back(Point(6, 7));
		startsnake2.emplace_back(Point(33, 16));
		startsnake2.emplace_back(Point(7, 6));
		startsnake2.emplace_back(Point(32, 15));
		startsnake2.emplace_back(Point(8, 5));
		startsnake2.emplace_back(Point(31, 14));
		startsnake2.emplace_back(Point(9, 4));

		startsnake.emplace_back(Point(0, 14));//蛇形1
		startsnake.emplace_back(Point(40, 4));
		startsnake.emplace_back(Point(1, 14));
		startsnake.emplace_back(Point(39, 4));
		startsnake.emplace_back(Point(2, 15));
		startsnake.emplace_back(Point(38, 5));
		startsnake.emplace_back(Point(3, 16));
		startsnake.emplace_back(Point(37, 6));
		startsnake.emplace_back(Point(4, 17));
		startsnake.emplace_back(Point(36, 7));
		startsnake.emplace_back(Point(5, 18));
		startsnake.emplace_back(Point(35, 8));
		startsnake.emplace_back(Point(6, 17));
		startsnake.emplace_back(Point(34, 7));
		startsnake.emplace_back(Point(7, 16));
		startsnake.emplace_back(Point(33, 6));
		startsnake.emplace_back(Point(8, 15));
		startsnake.emplace_back(Point(32, 5));
		startsnake.emplace_back(Point(9, 14));
		startsnake.emplace_back(Point(31, 4));

		startsnake3.emplace_back(Point(0, 14));//蛇形3
		startsnake3.emplace_back(Point(40, 14));
		startsnake3.emplace_back(Point(1, 14));
		startsnake3.emplace_back(Point(39, 14));
		startsnake3.emplace_back(Point(2, 15));
		startsnake3.emplace_back(Point(38, 15));
		startsnake3.emplace_back(Point(3, 16));
		startsnake3.emplace_back(Point(37, 16));
		startsnake3.emplace_back(Point(4, 17));
		startsnake3.emplace_back(Point(36, 17));
		startsnake3.emplace_back(Point(5, 18));
		startsnake3.emplace_back(Point(35, 18));
		startsnake3.emplace_back(Point(6, 17));
		startsnake3.emplace_back(Point(34, 17));
		startsnake3.emplace_back(Point(7, 16));
		startsnake3.emplace_back(Point(33, 16));
		startsnake3.emplace_back(Point(8, 15));
		startsnake3.emplace_back(Point(32, 15));
		startsnake3.emplace_back(Point(9, 14));
		startsnake3.emplace_back(Point(31, 14));

		startsnake4.emplace_back(Point(40, 14));//蛇形右中
		startsnake4.emplace_back(Point(39, 14));
		startsnake4.emplace_back(Point(38, 15));
		startsnake4.emplace_back(Point(37,16));
		startsnake4.emplace_back(Point(36,17));
		startsnake4.emplace_back(Point(35,18));
		startsnake4.emplace_back(Point(34,17));
		startsnake4.emplace_back(Point(33, 16));
		startsnake4.emplace_back(Point(32, 15));
		startsnake4.emplace_back(Point(31, 14));

		startsnake5.emplace_back(Point(0, 14));//蛇形左中
		startsnake5.emplace_back(Point(1, 14));
		startsnake5.emplace_back(Point(2, 15));
		startsnake5.emplace_back(Point(3, 16));
		startsnake5.emplace_back(Point(4, 17));
		startsnake5.emplace_back(Point(5, 18));
		startsnake5.emplace_back(Point(6, 17));
		startsnake5.emplace_back(Point(7, 16));
		startsnake5.emplace_back(Point(8, 15));
		startsnake5.emplace_back(Point(9, 14));

		startsnake6.emplace_back(Point(0, 4));//蛇形左上
		startsnake6.emplace_back(Point(1, 4));
		startsnake6.emplace_back(Point(2, 5));
		startsnake6.emplace_back(Point(3, 6));
		startsnake6.emplace_back(Point(4, 7));
		startsnake6.emplace_back(Point(5, 8));
		startsnake6.emplace_back(Point(6, 7));
		startsnake6.emplace_back(Point(7, 6));
		startsnake6.emplace_back(Point(8, 5));
		startsnake6.emplace_back(Point(9, 4));

		startsnake7.emplace_back(Point(40, 4));//蛇形右上
		startsnake7.emplace_back(Point(39, 4));
		startsnake7.emplace_back(Point(38, 5));
		startsnake7.emplace_back(Point(37, 6));
		startsnake7.emplace_back(Point(36, 7));
		startsnake7.emplace_back(Point(35, 8));
		startsnake7.emplace_back(Point(34, 7));
		startsnake7.emplace_back(Point(33, 6));
		startsnake7.emplace_back(Point(32, 5));
		startsnake7.emplace_back(Point(31, 4));

		startsnake8.emplace_back(Point(0, 14));//蛇形左中2
		startsnake8.emplace_back(Point(1, 14));
		startsnake8.emplace_back(Point(2, 15));
		startsnake8.emplace_back(Point(3, 16));
		startsnake8.emplace_back(Point(4, 17));
		startsnake8.emplace_back(Point(5, 18));
		startsnake8.emplace_back(Point(6, 17));
		startsnake8.emplace_back(Point(7, 16));
		startsnake8.emplace_back(Point(8, 15));
		startsnake8.emplace_back(Point(9, 14));

		startsnake9.emplace_back(Point(40, 14));//蛇形右中2
		startsnake9.emplace_back(Point(39, 14));
		startsnake9.emplace_back(Point(38, 15));
		startsnake9.emplace_back(Point(37, 16));
		startsnake9.emplace_back(Point(36, 17));
		startsnake9.emplace_back(Point(35, 18));
		startsnake9.emplace_back(Point(34, 17));
		startsnake9.emplace_back(Point(33, 16));
		startsnake9.emplace_back(Point(32, 15));
		startsnake9.emplace_back(Point(31, 14));

		textsnake.emplace_back(Point(-26, 14));//S
		textsnake.emplace_back(Point(-25, 14));
		textsnake.emplace_back(Point(-27, 15));
		textsnake.emplace_back(Point(-26, 16));
		textsnake.emplace_back(Point(-25, 17));
		textsnake.emplace_back(Point(-27, 18));
		textsnake.emplace_back(Point(-26, 18));

		textsnake.emplace_back(Point(-23, 14));//N
		textsnake.emplace_back(Point(-23, 15));
		textsnake.emplace_back(Point(-23, 16));
		textsnake.emplace_back(Point(-23, 17));
		textsnake.emplace_back(Point(-23, 18));
		textsnake.emplace_back(Point(-22, 15));
		textsnake.emplace_back(Point(-21, 16));
		textsnake.emplace_back(Point(-20, 17));
		textsnake.emplace_back(Point(-19, 14));
		textsnake.emplace_back(Point(-19, 15));
		textsnake.emplace_back(Point(-19, 16));
		textsnake.emplace_back(Point(-19, 17));
		textsnake.emplace_back(Point(-19, 18));

		textsnake.emplace_back(Point(-17, 18));//A
		textsnake.emplace_back(Point(-16, 17));
		textsnake.emplace_back(Point(-15, 16));
		textsnake.emplace_back(Point(-14, 15));
		textsnake.emplace_back(Point(-14, 16));
		textsnake.emplace_back(Point(-13, 14));
		textsnake.emplace_back(Point(-13, 16));
		textsnake.emplace_back(Point(-12, 15));
		textsnake.emplace_back(Point(-12, 16));
		textsnake.emplace_back(Point(-11, 16));
		textsnake.emplace_back(Point(-10, 17));
		textsnake.emplace_back(Point(-9, 18));

		textsnake.emplace_back(Point(-7, 14));//K
		textsnake.emplace_back(Point(-7, 15));
		textsnake.emplace_back(Point(-7, 16));
		textsnake.emplace_back(Point(-7, 17));
		textsnake.emplace_back(Point(-7, 18));
		textsnake.emplace_back(Point(-6, 16));
		textsnake.emplace_back(Point(-5, 15));
		textsnake.emplace_back(Point(-5, 17));
		textsnake.emplace_back(Point(-4, 14));
		textsnake.emplace_back(Point(-4, 18));

		textsnake.emplace_back(Point(-2, 14));//E
		textsnake.emplace_back(Point(-2, 15));
		textsnake.emplace_back(Point(-2, 16));
		textsnake.emplace_back(Point(-2, 17));
		textsnake.emplace_back(Point(-2, 18));
		textsnake.emplace_back(Point(-1, 14));
		textsnake.emplace_back(Point(-1, 16));
		textsnake.emplace_back(Point(-1, 18));
		textsnake.emplace_back(Point(0, 14));
		textsnake.emplace_back(Point(0, 16));
		textsnake.emplace_back(Point(0, 18));
	}
	void PrintFirst();
	void PrintFirst2();
	void PrintFirst3();
	void PrintSecond();
	void PrintSecond2();
	void PrintSecond3();
	void PrintThird();
	void PrintThird2();
	void PrintThird3();
	void PrintFive();
	void PrintText();
	void ClearText();
	void Action();
private:
	std::deque<Point> startsnake;//开始动画中的蛇
	std::deque<Point>startsnake2;//开始另外一条蛇2
	std::deque<Point>startsnake3;//开始另外一条蛇3
	std::deque<Point>startsnake4;//开始另外一条蛇4
	std::deque<Point>startsnake5;//开始另外一条蛇4
	std::deque<Point>startsnake6;//开始另外一条蛇4
	std::deque<Point>startsnake7;//开始另外一条蛇4
	std::deque<Point>startsnake8;//开始另外一条蛇4
	std::deque<Point>startsnake9;//开始另外一条蛇4
	std::vector<Point> textsnake;//开始动画中的文字
	int speed;//动画的速度
};
#endif // STRATINTERFACE_H
