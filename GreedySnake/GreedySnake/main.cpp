#include "controller.h"
int main()  // �������
{
    Start();  // ��ʼ����
    // ��Ϸһ��ѭ������Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������ 
    while (true)  
    {          
        Select();  // ѡ�����
        DrawGame();  // ������Ϸ����    
        // ������Ϸ����ѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp
        int tmp = PlayGame();  
        if (tmp == 1)  // ����ֵΪ1ʱ���¿�ʼ��Ϸ 
        {            
            ReStart();  // ���¿�ʼ����
            continue;
        }
        else if (tmp == 2)  // ����ֵΪ2ʱ�˳���Ϸ
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
