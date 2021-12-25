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

void Start()  // ��ʼ����
{
	SetWindowSize(41, 32);  // ���ô��ڴ�С
	PlaySound(TEXT("mc\\��ʼ����.wav"), NULL, SND_LOOP | SND_ASYNC);
	// ��������أ���������˸Ӱ����Ϸ����	
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);  
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);

	SetColor(2);  // ���ÿ�ʼ������ɫ
	StartInterface* start = new StartInterface(35);  // ��̬����һ��StartInterface��start
	start->Action();  // ��ʼ����
	delete start;  // �ͷ��ڴ�ռ�

	// ���ùر�λ�ã��������ʾ��ȴ�������������
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start... ";
	SetCursorPosition(13, 27);
	system("pause");
}

void ReStart()
{
	SetColor(2);  // ���ÿ�ʼ������ɫ��ReStart������������С����Ҫ��������SetColor����
	system("cls");  // ����
	StartInterface* start = new StartInterface(0);  // ��̬����һ��StartInterface��start
	start->Action();  // ��ʼ����
	delete start;  // �ͷ��ڴ�ռ�
}

void Select()  // ѡ�����
{
	// ��ʼ���÷ּ��÷ֲ���
	score_A = 0;
	score_B = 0;
	
	// ��ʼ��ģʽ����ѡ��
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "��ѡ����Ϸģʽ��";
	SetCursorPosition(6, 22);
	std::cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(27, 22);
	SetBackColor();  // ��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	std::cout << "����ģʽ";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "˫��ģʽ";
	SetCursorPosition(27, 26);
	std::cout << "�˻�ģʽ";

	// ���·����ѡ��ģ��
	int ch;  // ��¼����ֵ
	mode = 1;  // ��¼ѡ�����ʼѡ���һ��
	bool flag = false;  // ��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch())) 
	{
		switch (ch)  // ��������
		{
		case 72:  // UP�Ϸ����
			if (mode > 1)  // ����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (mode) 
				{
				case 2:
					SetCursorPosition(27, 22);  // ����ѡ�������ñ���ɫ
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);  // ����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					std::cout << "˫��ģʽ";
					--mode;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "˫��ģʽ";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "�˻�ģʽ";
					--mode;
					break;
				}
			}
			break;

		case 80:  // DOWN�·����
			if (mode < 3) 
			{
				switch (mode) 
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "˫��ģʽ";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "����ģʽ";
					++mode;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "�˻�ģʽ";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "˫��ģʽ";
					++mode;
					break;
				}
			}
			break;

		case 13:  // Enter�س���
			flag = true;
			break;
		default:  // ��Ч����
			break;
		}
		if (flag) break;  // ����Enter�س���ȷ�ϣ��˳��������ѭ��
	}

	//��ʼ���ѶȽ���ѡ��
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(6, 22);
	std::cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(27, 22);
	SetBackColor();  // ��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	std::cout << "��ģʽ";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "��ͨģʽ";
	SetCursorPosition(27, 26);
	std::cout << "����ģʽ";
	SetCursorPosition(27, 28);
	std::cout << "����ģʽ";

	// ���·����ѡ��ģ��
	key = 1;  // ��¼ѡ�����ʼѡ���һ��
	flag = false;  // ��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch())) 
	{
		switch (ch)  // ��������
		{
		case 72:  // UP�Ϸ����
			if (key > 1)  // ����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key) 
				{
				case 2:
					SetCursorPosition(27, 22);//����ѡ�������ñ���ɫ
					SetBackColor();
					std::cout << "��ģʽ";
					SetCursorPosition(27, 24);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					std::cout << "��ͨģʽ";
					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";
					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "����ģʽ";
					--key;
					break;
				}
			}
			break;

		case 80:  // DOWN�·����
			if (key < 4) 
			{
				switch (key) 
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "��ģʽ";
					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";
					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "����ģʽ";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";
					++key;
					break;
				}
			}
			break;

		case 13:  // Enter�س���
			flag = true;
			break;
		default:  // ��Ч����
			break;
		}
		if (flag) break;  // ����Enter�س���ȷ�ϣ��˳��������ѭ��
	}

	switch (key)  // ������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��
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
	PlaySound(NULL, NULL, SND_PURGE); //����ֹͣ
}

void DrawGame()  // ������Ϸ����
{
	system("cls");  // ����

	//���Ƶ�ͼ
	SetColor(1);
	srand((unsigned)time(NULL));
	mapnum = rand();
	Map* init_map = new Map(mapnum);
	init_map->PrintInitmap();
	delete init_map;

	//���Ʋ����
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "̰����";
	SetCursorPosition(31, 4);
	std::cout << "ģʽ��";
	SetCursorPosition(36, 5);
	switch (mode) 
	{
	case 1:
		PlaySound(TEXT("mc\\����ģʽ.wav"), NULL, SND_LOOP | SND_ASYNC);
		std::cout << "����ģʽ";
		break;
	case 2:
		PlaySound(TEXT("mc\\˫��ģʽ.wav"), NULL, SND_LOOP | SND_ASYNC);
		std::cout << "˫��ģʽ";
		break;
	case 3:
		PlaySound(TEXT("mc\\�˻�ģʽ.wav"), NULL, SND_LOOP | SND_ASYNC);
		std::cout << "�˻�ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "�Ѷȣ�";
	SetCursorPosition(36, 8);
	switch (key) 
	{
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "����ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 10);
	std::cout << "���ߵ÷֣�";
	SetCursorPosition(37, 11);
	std::cout << "     0";
	if (mode == 2 || mode == 3)
	{
		SetCursorPosition(31, 13);
		if (mode == 2)
		{
			std::cout << "���ߵ÷֣�";
		}
		else
		{
			std::cout << "���ߵ÷֣�";
		}
		SetCursorPosition(37, 14);
		std::cout << "     0";
	}
	if (mode == 2)
	{
		SetCursorPosition(32, 16);
		std::cout << "���߷�����ƶ�"; 
		SetCursorPosition(32, 18);
		std::cout << "����wasd���ƶ�";
	}
	else
	{
		SetCursorPosition(32, 18);
		std::cout << "���߷�����ƶ�";
	}
	SetCursorPosition(33, 20);
	std::cout << " ESC����ͣ";
}

int PlayGame()  // ��Ϸ����ѭ��
{
	// ��ʼ���ߺ�ʳ��
	Map* init_map = new Map(mapnum);
	Snake* csnake_A = new Snake();  // ��ʼ����A
	Snake* csnake_B = csnake_A;  // ��B�粻��ʱ��ʼ��InitSnake�����ᱨ��
	switch (mode)  // ������ѡģʽ��ʼ����B
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
	srand((unsigned)time(NULL));  // ������������ӣ����û��ʳ��ĳ���λ�ý���̶�
	cfood->DrawFood(*csnake_A, *csnake_B, *init_map);

	/*��Ϸѭ��*/
	// �ж��Ƿ��д�����
	while ((csnake_A->IfAlive(*csnake_B, *init_map) || csnake_B->IfAlive(*csnake_A, *init_map))) 
	{
	    // ���������������ɾ������
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

		// ���ܰ����Ե������򼰵���ѡ��˵�
		if (!Snake::ChangeDirection(*csnake_A, *csnake_B))  // ��Esc��ʱ 
		{  
			int tmp = Menu();  // ���Ʋ˵������õ�����ֵ
			switch (tmp)
			{
			case 1:  // ������Ϸ
				break;
			case 2:  // ���¿�ʼ
				if (csnake_A != csnake_B) delete csnake_A;
				delete csnake_B;
				delete cfood;
				PlaySound(NULL, NULL, SND_PURGE);	//����ֹͣ
				return 1;  // ��1��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ���¿�ʼ
			case 3:  // �˳���Ϸ
				if (csnake_A != csnake_B) delete csnake_A;
				delete csnake_B;
				delete cfood;
				PlaySound(NULL, NULL, SND_PURGE);	//����ֹͣ
				return 2;  // ��2��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ�˳���Ϸ
			default:
				break;
			}
		}

		if (mode == 3 && Ifsnake_B)  // ai��������ţ�����ú������㷽��
		{
			Machine(*csnake_B, *csnake_A, *cfood, *init_map);
		}	

		if (csnake_A != csnake_B)  // �ж��Ƿ������ߣ����Բ�������B�Ƿ����ж�  
		{
			// ԭ�ļ����ж��Ƿ�Ե�ʳ�����ƶ��������big_flag������׼ȷ��������˸�쳣�����޸��߼���NormalMove���������ƶ�ͷ�����ٸ����Ƿ�Ե�ʳ�����ƶ�β��
			csnake_A->Move();  // ��A����
			csnake_B->Move();  // ��B����
			if (csnake_A->GetFood(*cfood))  //GetBigFoodΪ��ʱ��ͬʱ�޸����꣬Ӧʹ��Ƕ�������ж�
			{
				if (csnake_B->GetBigFood(*cfood))  // ���һ����A�Ե���ͨʳ���B�Ե���ʱʳ��
				{
					Ifsnake_B = false;  // ��־��A�ӷ�
					UpdateScore(1);  // ���·�����1Ϊ����Ȩ��
					Ifsnake_B = true;  // ��־��B�ӷ�
					UpdateScore(cfood->GetProgressBar() / 5);  // ����������ʱʳ�������ȷ��
					RewriteScore();  // ���»��Ʒ���
					cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // ������ʳ��
				}
				else  // ���������A�Ե���ͨʳ���Bû�гԵ�ʳ��
				{
					csnake_B->NormalMove();  // ��B�����ƶ�
					Ifsnake_B = false;
					UpdateScore(1);  // ���·�����1Ϊ����Ȩ��
					Ifsnake_B = true;  // ֤����B������
					RewriteScore();  // ���»��Ʒ���
					cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // ������ʳ��
				}
			}
			else if (csnake_B->GetFood(*cfood))
			{
				if (csnake_A->GetBigFood(*cfood))  // ���������A�Ե���ʱʳ���B�Ե���ͨʳ��
				{
					Ifsnake_B = false;
					UpdateScore(cfood->GetProgressBar() / 5);  // ����������ʱʳ�������ȷ��			
					Ifsnake_B = true;  // ֤����B������
					UpdateScore(1);  // ���·�����1Ϊ����Ȩ��
					RewriteScore();  // ���»��Ʒ���
					cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // ������ʳ��
				}
				else  // ����ģ���Aû�гԵ�ʳ���B�Ե���ͨʳ��
				{
					csnake_A->NormalMove();  // ��A�����ƶ�
					UpdateScore(1);  // ���·�����1Ϊ����Ȩ��
					RewriteScore();  // ���»��Ʒ���
					cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // ������ʳ��
				}
			}
			else
			{
				if (csnake_A->GetBigFood(*cfood))  // ����壺��A�Ե���ʱʳ���Bû�гԵ�ʳ��
				{
					csnake_B->NormalMove();  // ��B�����ƶ�
					Ifsnake_B = false;
					UpdateScore(cfood->GetProgressBar() / 5);  // ����������ʱʳ�������ȷ��
					Ifsnake_B = true;
					RewriteScore();
				}
				else if (csnake_B->GetBigFood(*cfood))  // ���������Aû�гԵ�ʳ���B�Ե���ʱʳ��
				{
					csnake_A->NormalMove();  // ��A�����ƶ�
					UpdateScore(cfood->GetProgressBar() / 5);  // ����������ʱʳ�������ȷ��
					RewriteScore();
				}
				else  // ����ߣ���A��B��û�гԵ�ʳ��
				{
					csnake_A->NormalMove();  // ��A�����ƶ�
					csnake_B->NormalMove();  // ��B�����ƶ�
				}
			}
		}
		else  // ֻ��һ���ߴ��ʱ
		{
			csnake_A->Move();
			if (csnake_A->GetFood(*cfood))  // ��A�Ե�ʳ��
			{
				UpdateScore(1);  // ���·�����1Ϊ����Ȩ��
				RewriteScore();  // ���»��Ʒ���
				cfood->DrawFood(*csnake_A, *csnake_B, *init_map);  // ������ʳ��
			}
			else if (csnake_A->GetBigFood(*cfood))  // ��A�Ե���ʱʳ��
			{
				UpdateScore(cfood->GetProgressBar() / 5);  // ����������ʱʳ�������ȷ��
				RewriteScore();
			}
			else 
			{
				csnake_A->NormalMove();  // ��A�����ƶ�
			}
		}

		if (cfood->GetBigFlag())  // �����ʱ����ʱʳ���˸��
		{
			cfood->FlashBigFood();
		}

		Sleep(speed);  // �����ߵ��ƶ�Ч��
	}

	// ��ȫ������
	int tmp = GameOver();  // ������Ϸ�������棬��������ѡ��
	// �ͷŷ�����ڴ�ռ�
	if (csnake_A != csnake_B) delete csnake_A;
	delete csnake_B;
	delete cfood;
	delete init_map;
	switch (tmp)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 2;
	}	
}

void UpdateScore(const int& tmp)  // ���·���
{
	if (!Ifsnake_B)
	{
		score_A += key * 10 * tmp;  // ���÷���������Ϸ�Ѷȼ����˵Ĳ���tmpȷ��
	}
	else
	{
		score_B += key * 10 * tmp;
	}
}

void RewriteScore()  // �ػ����
{
	// Ϊ���ַ���β�����룬������������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������
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

int Menu()  // ѡ��˵�
{
	// ���Ʋ˵�
	SetColor(11);
	SetCursorPosition(32, 23);
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(34, 25);
	SetBackColor();
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(34, 27);
	SetColor(11);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34, 29);
	std::cout << "�˳���Ϸ";

	// ѡ�񲿷�
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
					std::cout << "������Ϸ";
					SetCursorPosition(34, 27);
					SetColor(11);
					std::cout << "���¿�ʼ";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 27);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 29);
					SetColor(11);
					std::cout << "�˳���Ϸ";
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
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "������Ϸ";
					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 29);
					SetBackColor();
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 27);
					SetColor(11);
					std::cout << "���¿�ʼ";
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

	if (tmp_key == 1)  // ѡ�������Ϸ���򽫲˵�����
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

int GameOver()  // ��Ϸ��������
{
	PlaySound(TEXT("mc\\ʧ��.wav"), NULL, SND_FILENAME | SND_ASYNC);
	// ������Ϸ��������
	Sleep(300);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "������������������������������������������������������������������������������������";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ��               Game Over !!!             ��";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ��                                         ��";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ��            ���߷���Ϊ��                 ��";
	SetCursorPosition(24, 11);
	std::cout << score_A;
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ��                                         ��";

	Sleep(30);
	SetCursorPosition(9, 13);
	if (mode == 2 || mode == 3)
	{
		if (mode == 2)
		{
			std::cout << " ��            ���߷���Ϊ��                 ��";
		}
		else
		{
			std::cout << " ��            ���߷���Ϊ��                 ��";
		}
		SetCursorPosition(24, 13);
		std::cout << score_B;
	}
	else
	{	
		std::cout << " ��                                         ��"; 	
	}
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ��                                         ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	switch (mode)
	{
	case 1:
		std::cout << " ��             ���ź��������              ��";
		break;
	case 2:
		if (score_A > score_B)
		{
			std::cout << " ��            ��ϲ�����߻�ʤ               ��";
		}
		else if (score_A < score_B)
		{
			std::cout << " ��            ��ϲ�����߻�ʤ               ��";
		}
		else
		{
			std::cout << " ��             �ðɣ���ƽ��                ��";
		}
		break;
	case 3:
		if (score_A > score_B)
		{
			std::cout << " ��         ������������ҫ���㺴��          ��";
		}
		else if (score_A < score_B)
		{
			std::cout << " ��           ����ģ�����������            ��";
		}
		else
		{
			std::cout << " ��             �ðɣ���ƽ��                ��";
		}
		break;
	default:
		break;
	}
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ��                                         ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ��              �Ƿ�����һ�֣�             ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ��                                         ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼ ��";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ��                                         ��";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "������������������������������������������������������������������������������������";

	Sleep(100);
	SetCursorPosition(12, 19);
	SetBackColor();
	std::cout << "�ţ��õ�";

	// ѡ�񲿷�
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
				std::cout << "�ţ��õ�";
				SetCursorPosition(20, 19);
				SetColor(11);
				std::cout << "���ˣ�����ѧϰ����˼";
				--tmp_key;
			}
			break;

		case 77:  // RIGHT
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 19);
				SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(12, 19);
				SetColor(11);
				std::cout << "�ţ��õ�";
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
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 1;
	}
}
