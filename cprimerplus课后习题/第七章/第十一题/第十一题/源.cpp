#include<stdio.h>
#define A 2.05
#define B 1.15
#define C 1.09
int main(void)
{
	char ch_a,ch_b;
	float bon,bon_a=0,bon_b=0,bon_c=0,weight,money,get=0,press;
	printf("��ʼ����?��Y/N��\n");
	while ((ch_a=getchar())=='Y')
	{
		weight = 0;
		money = 0;
		while(1)
		{
			printf("��ѡ�����ࣺ\n");
			printf("a)��У�2.05Ԫ��    b)��ˣ�1.15Ԫ��\n");
			printf("c)���ܲ���1.09Ԫ��  p)�˳�ѡ��\n");
			while ((ch_b = getchar()) == '\n')
				continue;
			if (ch_b>= 'a'&&ch_b <= 'c')
			{
				switch (ch_b)
				{
				case 'a':
					printf("��������еİ�����\n");
					scanf("%f", &bon);
					bon_a += bon;
					break;
				case 'b':
					printf("��������˵İ�����\n");
					scanf("%f", &bon);
					bon_b += bon;
					break;
				case 'c':
					printf("��������ܲ��İ�����\n");
					scanf("%f", &bon);
					bon_c += bon;
					break;
				default:
					break;
				}
			}
			else if (ch_b == 'p')
				break;
			else
			{
				printf("������������ȷѡ��\n");
				continue;
			}
		} 
		money = bon_a*A + bon_b*B + bon_c*C;
		bon = bon_a + bon_b + bon_c;
		if (money >= 100)
		{
			get = money*0.05;
			money *= 0.95;
		}
		if (bon <= 5)
		{
			press = 6.5;
		}
		else if (5 < bon&& bon<=20)
		{
			press = 14;
		}
		else
		{
			press = 14 + (bon - 20)*0.5;
		}
		printf("������Ϊ:%f,�߲˷���Ϊ:%f,�ۿ�Ϊ:%f,�˷�Ϊ:%f,�ܷ���Ϊ:%f\n",bon,money,get,press,money+press);
		printf("��ʼ����?��Y/N��\n");
	}
	getchar();
	return 0;
	getchar();
}