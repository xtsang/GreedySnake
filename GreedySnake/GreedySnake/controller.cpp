#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#pragma comment (lib, "winmm.lib")

static int speed;
static int mode;
static int key;
static int mapnum;
static int score_A;
static int score_B;
static bool Ifsnake_B;

void Start()  // 开始界面
{
	SetWindowSize(41, 32);  // 设置窗口大小
	PlaySound(TEXT("mc\\开始音乐.wav"), NULL, SND_LOOP | SND_ASYNC);
	// 将光标隐藏，避免光标闪烁影响游戏体验	
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);  
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);

	SetColor(2);  // 设置开始动画颜色
	StartInterface* start = new StartInterface(35);  // 动态分配一个StartInterface类start
	start->Action();  // 开始动画
	delete start;  // 释放内存空间

	// 设置关标位置，并输出提示语，等待任意键输入结束
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start... ";
	SetCursorPosition(13, 27);
	system("pause");
}

void ReStart()
{
	SetColor(2);  // 设置开始动画颜色，ReStart函数作用域最小，故要单独设置SetColor参数
	system("cls");  // 清屏
	StartInterface* start = new StartInterface(0);  // 动态分配一个StartInterface类start
	start->Action();  // 开始动画
	delete start;  // 释放内存空间
}

void Select()  // 选择界面
{
	// 初始化得分及得分参数
	score_A = 0;
	score_B = 0;
	
	// 初始化模式界面选项
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏模式：";
	SetCursorPosition(6, 22);
	std::cout << "(上下键选择,回车确认)";
	SetCursorPosition(27, 22);
	SetBackColor();  // 第一个选项设置背景色以表示当前选中
	std::cout << "单人模式";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "双人模式";
	SetCursorPosition(27, 26);
	std::cout << "人机模式";

	// 上下方向键选择模块
	int ch;  // 记录键入值
	mode = 1;  // 记录选中项，初始选择第一个
	bool flag = false;  // 记录是否键入Enter键标记，初始置为否
	while ((ch = _getch())) 
	{
		switch (ch)  // 检测输入键
		{
		case 72:  // UP上方向键
			if (mode > 1)  // 当此时选中项为第一项时，UP上方向键无效
			{
				switch (mode) 
				{
				case 2:
					SetCursorPosition(27, 22);  // 给待选中项设置背景色
					SetBackColor();
					std::cout << "单人模式";
					SetCursorPosition(27, 24);  // 将已选中项取消我背景色
					SetColor(3);
					std::cout << "双人模式";
					--mode;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "双人模式";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "人机模式";
					--mode;
					break;
				}
			}
			break;

		case 80:  // DOWN下方向键
			if (mode < 3) 
			{
				switch (mode) 
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "双人模式";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "单人模式";
					++mode;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "人机模式";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "双人模式";
					++mode;
					break;
				}
			}
			break;

		case 13:  // Enter回车键
			flag = true;
			break;
		default:  // 无效按键
			break;
		}
		if (flag) break;  // 输入Enter回车键确认，退出检查输入循环
	}

	//初始化难度界面选项
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏难度：";
	SetCursorPosition(6, 22);
	std::cout << "(上下键选择,回车确认)";
	SetCursorPosition(27, 22);
	SetBackColor();  // 第一个选项设置背景色以表示当前选中
	std::cout << "简单模式";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "普通模式";
	SetCursorPosition(27, 26);
	std::cout << "困难模式";
	SetCursorPosition(27, 28);
	std::cout << "炼狱模式";

	// 上下方向键选择模块
	key = 1;  // 记录选中项，初始选择第一个
	flag = false;  // 记录是否键入Enter键标记，初始置为否
	while ((ch = _getch())) 
	{
		switch (ch)  // 检测输入键
		{
		case 72:  // UP上方向键
			if (key > 1)  // 当此时选中项为第一项时，UP上方向键无效
			{
				switch (key) 
				{
				case 2:
					SetCursorPosition(27, 22);//给待选中项设置背景色
					SetBackColor();
					std::cout << "简单模式";
					SetCursorPosition(27, 24);//将已选中项取消我背景色
					SetColor(3);
					std::cout << "普通模式";
					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";
					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";
					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "炼狱模式";
					--key;
					break;
				}
			}
			break;

		case 80:  // DOWN下方向键
			if (key < 4) 
			{
				switch (key) 
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "简单模式";
					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";
					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "炼狱模式";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";
					++key;
					break;
				}
			}
			break;

		case 13:  // Enter回车键
			flag = true;
			break;
		default:  // 无效按键
			break;
		}
		if (flag) break;  // 输入Enter回车键确认，退出检查输入循环
	}

	switch (key)  // 根据所选选项设置蛇的移动速度，speed值越小，速度越快
	{
	case 1:
		speed = 135;
		break;
	case 2:
		speed = 100;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}
	PlaySound(NULL, NULL, SND_PURGE); //音乐停止
}

void DrawGame()  // 绘制游戏界面
{
	system("cls");  // 清屏

	//绘制地图
	SetColor(1);
	srand((unsigned)time(NULL));
	mapnum = rand();
	Map* init_map = new Map(mapnum);
	init_map->PrintInitmap();
	delete init_map;

	//绘制侧边栏
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "模式：";
	SetCursorPosition(36, 5);
	switch (mode) 
	{
	case 1:
		PlaySound(TEXT("mc\\单机模式.wav"), NULL, SND_LOOP | SND_ASYNC);
		std::cout << "单人模式";
		break;
	case 2:
		PlaySound(TEXT("mc\\双人模式.wav"), NULL, SND_LOOP | SND_ASYNC);
		std::cout << "双人模式";
		break;
	case 3:
		PlaySound(TEXT("mc\\人机模式.wav"), NULL, SND_LOOP | SND_ASYNC);
		std::cout << "人机模式";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "难度：";
	SetCursorPosition(36, 8);
	switch (key) 
	{
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "炼狱模式";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 10);
	std::cout << "黄蛇得分：";
	SetCursorPosition(37, 11);
	std::cout << "     0";
	if (mode == 2 || mode == 3)
	{
		SetCursorPosition(31, 13);
		if (mode == 2)
		{
			std::cout << "红蛇得分：";
		}
		else
		{
			std::cout << "绿蛇得分：";
		}
		SetCursorPosition(37, 14);
		std::cout << "     0";
	}
	if (mode == 2)
	{
		SetCursorPosition(32, 16);
		std::cout << "黄蛇方向键移动"; 
		SetCursorPosition(32, 18);
		std::cout << "红蛇wasd键移动";
	}
	else
	{
		SetCursorPosition(32, 18);
		std::cout << "黄蛇方向键移动";
	}
	SetCursorPosition(33, 20);
	std::cout << " ESC键暂停";
}

int PlayGame()  // 游戏二级循环
{
	// 初始化蛇和食物
	Map* init_map = new Map(mapnum);
	Snake* csnake_A = new Snake();  // 初始化蛇A
	Snake* csnake_B = csnake_A;  // 蛇B如不此时初始化InitSnake函数会报错
	switch (mode)  // 根据所选模式初始化蛇B
	{
	case 1:
		Ifsnake_B = false;
		break;
	case 2:
		csnake_B = new Snake(9, 4);
		Ifsnake_B = true;
		break;
	case 3:
		csnake_B = new Snake(9, 2);
		Ifsnake_B = true;
		break;
	default:
		Ifsnake_B = false;
		break;
	}
	csnake_A->InitSnake();  
	csnake_B->InitSnake();

	Food* cfood = new Food();
	srand((unsigned)time(NULL));  // 设置随机数种子，如果没有食物的出现位置将会固定
	cfood->DrawFood(*csnake_A, *csnake_B, *init_map);

	/*游戏循环*/
	// 判断是否还有存活的蛇
	while ((csnake_A->IfAlive(*csnake_B, *init_map) || csnake_B->IfAlive(*csnake_A, *init_map))) 
	{
	    // 如果有蛇死亡进行删除操作
		if (!csnake_A->IfAlive(*csnake_B, *init_map))
		{
			csnake_A->Death(*csnake_B, *init_map);
			csnake_A = csnake_B;
			Ifsnake_B = true;
		}
		else if (!csnake_B->IfAlive(*csnake_A, *init_map))
		{
			csnake_B->Death(*csnake_A, *init_map);
			csnake_B = csnake_A;
			Ifsnake_B = false;
		}

		// 接受按键以调整方向及调出选择菜单
		if (!Snake::ChangeDirection(*csnake_A, *csnake_B))  // 按Esc键时 
		{  
			int tmp = Menu();  // 绘制菜单，并得到返回值
			switch (tmp)
			{
			case 1:  // 继续游戏
				break;
			case 2:  // 重新开始
				if (csnake_A != csnake_B) delete csnake_A;
				delete csnake_B;
				delete cfood;
				PlaySound(NULL, NULL, SND_PURGE);	//音乐停止
				return 1;  // 将1作为PlayGame函数的返回值返回到Game函数中，表示重新开始
			case 3:  // 退出游戏
				if (csnake_A != csnake_B) delete csnake_A;
				delete csnake_B;
				delete cfood;
				PlaySound(NULL, NULL, SND_PURGE);	//音乐停止
				return 2;  // 将2作为PlayGame函数的返回值返回到Game函数中，表示退出游戏
			default:
				break;
			}
		}

		if (mode == 3 && Ifsnake_B)  // ai蛇如果活着，则调用函数计算方向
		{
			Machine(*csnake_B, *csnake_A, *cfood, *init_map);
		}	

		if (csnake_A != csnake_B)  // 判断是否存活两蛇，所以不能用蛇B是否存活判断  
		{
			// 原文件先判断是否吃到食物再移动，会造成big_flag参数不准确，引起闪烁异常！故修改逻辑及NormalMove函数，先移动头部，再根据是否吃到食物来移动尾部
			csnake_A->Move();  // 蛇A增长
			csnake_B->Move();  // 蛇B增长
			if (csnake_A->GetFood(*cfood))  //GetBigFood为真时会同时修改坐标，应使用嵌套条件判断
			{
				if (csnake_B->GetBigFood(*cfood))  // 情况一：蛇A吃到普通食物，蛇B吃到限时食物
				{
					Ifsnake_B = false;  // 标志蛇A加分
					UpdateScore(1);  // 更新分数，1为分数权重
					Ifsnake_B = true;  // 标志蛇B加分
					UpdateScore(cfood->GetProgressBar() / 5);  // 分数根据限时食物进度条确定
					RewriteScore();  // 重新绘制分数
					cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // 绘制新食物
				}
				else  // 情况二：蛇A吃到普通食物，蛇B没有吃到食物
				{
					csnake_B->NormalMove();  // 蛇B正常移动
					Ifsnake_B = false;
					UpdateScore(1);  // 更新分数，1为分数权重
					Ifsnake_B = true;  // 证明蛇B还活着
					RewriteScore();  // 重新绘制分数
					cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // 绘制新食物
				}
			}
			else if (csnake_B->GetFood(*cfood))
			{
				if (csnake_A->GetBigFood(*cfood))  // 情况三：蛇A吃到限时食物，蛇B吃到普通食物
				{
					Ifsnake_B = false;
					UpdateScore(cfood->GetProgressBar() / 5);  // 分数根据限时食物进度条确定			
					Ifsnake_B = true;  // 证明蛇B还活着
					UpdateScore(1);  // 更新分数，1为分数权重
					RewriteScore();  // 重新绘制分数
					cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // 绘制新食物
				}
				else  // 情况四：蛇A没有吃到食物，蛇B吃到普通食物
				{
					csnake_A->NormalMove();  // 蛇A正常移动
					UpdateScore(1);  // 更新分数，1为分数权重
					RewriteScore();  // 重新绘制分数
					cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // 绘制新食物
				}
			}
			else
			{
				if (csnake_A->GetBigFood(*cfood))  // 情况五：蛇A吃到限时食物，蛇B没有吃到食物
				{
					csnake_B->NormalMove();  // 蛇B正常移动
					Ifsnake_B = false;
					UpdateScore(cfood->GetProgressBar() / 5);  // 分数根据限时食物进度条确定
					Ifsnake_B = true;
					RewriteScore();
				}
				else if (csnake_B->GetBigFood(*cfood))  // 情况六：蛇A没有吃到食物，蛇B吃到限时食物
				{
					csnake_A->NormalMove();  // 蛇A正常移动
					UpdateScore(cfood->GetProgressBar() / 5);  // 分数根据限时食物进度条确定
					RewriteScore();
				}
				else  // 情况七：蛇A蛇B都没有吃到食物
				{
					csnake_A->NormalMove();  // 蛇A正常移动
					csnake_B->NormalMove();  // 蛇B正常移动
				}
			}
		}
		else  // 只有一条蛇存活时
		{
			csnake_A->Move();
			if (csnake_A->GetFood(*cfood))  // 蛇A吃到食物
			{
				UpdateScore(1);  // 更新分数，1为分数权重
				RewriteScore();  // 重新绘制分数
				cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // 绘制新食物
			}
			else if (csnake_A->GetBigFood(*cfood))  // 蛇A吃到限时食物
			{
				UpdateScore(cfood->GetProgressBar() / 5);  // 分数根据限时食物进度条确定
				RewriteScore();
			}
			else 
			{
				csnake_A->NormalMove();  // 蛇A正常移动
			}
		}

		if (cfood->GetBigFlag())  // 如果此时有限时食物，闪烁它
		{
			cfood->FlashBigFood();
		}

		Sleep(speed);  // 制造蛇的移动效果
	}

	// 蛇全部死亡
	int tmp = GameOver();  // 绘制游戏结束界面，并返回所选项
	// 释放分配的内存空间
	if (csnake_A != csnake_B) delete csnake_A;
	delete csnake_B;
	delete cfood;
	delete init_map;
	switch (tmp)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 2;
	}	
}

void UpdateScore(const int& tmp)  // 更新分数
{
	if (!Ifsnake_B)
	{
		score_A += key * 10 * tmp;  // 所得分数根据游戏难度及传人的参数tmp确定
	}
	else
	{
		score_B += key * 10 * tmp;
	}
}

void RewriteScore()  // 重绘分数
{
	// 为保持分数尾部对齐，将最大分数设置为6位，计算当前分数位数，将剩余位数用空格补全，再输出分数
	if (score_A) 
	{
		SetCursorPosition(37, 11);
		SetColor(11);
		int bit = 0;
		int tmp = score_A;
		while (tmp != 0) 
		{
			++bit;
			tmp /= 10;
		}
		for (int i = 0; i < (6 - bit); ++i) 
		{
			std::cout << " ";
		}
		std::cout << score_A;
	}
	if (score_B) 
	{
		SetCursorPosition(37, 14);
		SetColor(11);
		int bit = 0;
		int tmp = score_B;
		while (tmp != 0) 
		{
			++bit;
			tmp /= 10;
		}
		for (int i = 0; i < (6 - bit); ++i) 
		{
			std::cout << " ";
		}
		std::cout << score_B;
	}
}

int Menu()  // 选择菜单
{
	// 绘制菜单
	SetColor(11);
	SetCursorPosition(32, 23);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34, 25);
	SetBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(34, 27);
	SetColor(11);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34, 29);
	std::cout << "退出游戏";

	// 选择部分
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch) 
		{
		case 72:  // UP
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "继续游戏";
					SetCursorPosition(34, 27);
					SetColor(11);
					std::cout << "重新开始";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 27);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 29);
					SetColor(11);
					std::cout << "退出游戏";
					--tmp_key;
					break;
				}
			}
			break;

		case 80:  // DOWN
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 27);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "继续游戏";
					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 29);
					SetBackColor();
					std::cout << "退出游戏";
					SetCursorPosition(34, 27);
					SetColor(11);
					std::cout << "重新开始";
					++tmp_key;
					break;
				}
			}
			break;

		case 13:  // Enter
			flag = true;
			break;
		default:
			break;
		}
		if (flag) break;
	}

	if (tmp_key == 1)  // 选择继续游戏，则将菜单擦除
	{
		SetCursorPosition(32, 23);
		std::cout << "      ";
		SetCursorPosition(34, 25);
		std::cout << "        ";
		SetCursorPosition(34, 27);
		std::cout << "        ";
		SetCursorPosition(34, 29);
		std::cout << "        ";
	}
	return tmp_key;
}

int GameOver()  // 游戏结束界面
{
	PlaySound(TEXT("mc\\失败.wav"), NULL, SND_FILENAME | SND_ASYNC);
	// 绘制游戏结束界面
	Sleep(300);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ┃               Game Over !!!             ┃";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ┃                                         ┃";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ┃            黄蛇分数为：                 ┃";
	SetCursorPosition(24, 11);
	std::cout << score_A;
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ┃                                         ┃";

	Sleep(30);
	SetCursorPosition(9, 13);
	if (mode == 2 || mode == 3)
	{
		if (mode == 2)
		{
			std::cout << " ┃            红蛇分数为：                 ┃";
		}
		else
		{
			std::cout << " ┃            绿蛇分数为：                 ┃";
		}
		SetCursorPosition(24, 13);
		std::cout << score_B;
	}
	else
	{	
		std::cout << " ┃                                         ┃"; 	
	}
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ┃                                         ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	switch (mode)
	{
	case 1:
		std::cout << " ┃             很遗憾，你挂了              ┃";
		break;
	case 2:
		if (score_A > score_B)
		{
			std::cout << " ┃            恭喜，黄蛇获胜               ┃";
		}
		else if (score_A < score_B)
		{
			std::cout << " ┃            恭喜，红蛇获胜               ┃";
		}
		else
		{
			std::cout << " ┃             好吧，打平了                ┃";
		}
		break;
	case 3:
		if (score_A > score_B)
		{
			std::cout << " ┃         ！！！人类荣耀由你捍卫          ┃";
		}
		else if (score_A < score_B)
		{
			std::cout << " ┃           别灰心，它还不完美            ┃";
		}
		else
		{
			std::cout << " ┃             好吧，打平了                ┃";
		}
		break;
	default:
		break;
	}
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ┃                                         ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ┃              是否再来一局？             ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ┃                                         ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ┃    嗯，好的        不了，还是学习有意思 ┃";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ┃                                         ┃";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	SetCursorPosition(12, 19);
	SetBackColor();
	std::cout << "嗯，好的";

	// 选择部分
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75:  // LEFT
			if (tmp_key > 1)
			{
				SetCursorPosition(12, 19);
				SetBackColor();
				std::cout << "嗯，好的";
				SetCursorPosition(20, 19);
				SetColor(11);
				std::cout << "不了，还是学习有意思";
				--tmp_key;
			}
			break;

		case 77:  // RIGHT
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 19);
				SetBackColor();
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(12, 19);
				SetColor(11);
				std::cout << "嗯，好的";
				++tmp_key;
			}
			break;

		case 13:  // Enter
			flag = true;
			break;
		default:
			break;
		}
		if (flag) break;
	}

	switch (tmp_key)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 1;
	}
}
