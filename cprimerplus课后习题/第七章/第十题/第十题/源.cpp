#include<stdio.h>
#define A 17850
#define B 23900
#define C 29750
#define D 14875
int main(void)
{
	long line;
	int option;
	float money,tax;
	do
	{
		printf("���������ͣ�\n");
		printf("1)����        2������\n");
		printf("3)�ѻ飬����   4���ѻ�����\n");
		if (scanf("%d", &option) == 1)
		{
			if (0 < option&&option < 5)
			{
				switch (option)
				{
				case 1:line = A;
					break;
				case 2:line = B;
					break;
				case 3:line = C;
					break;
				case 4:line = D;
					break;
				default:;
					break;
				}
				printf("�������\n");
				scanf("%f", &money);
				if (money <= line)
				{
					tax = money*0.15;
				}
				else
				{
					tax = line*0.15 + (money - line)*0.28;
				}
				printf("Ӧ����%f\n", tax);
			}
			else
			{
				printf("��������ȷѡ��\n");
				continue;
			}
		}
		else
			break;
	} while (1);
	getchar();
	getchar();
	return 0;
	getchar();
}