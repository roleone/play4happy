#include<stdio.h>
#define A 8.75
#define B 9.33
#define C 10.00
#define D 11.2
#define tax1 0.15
#define tax2 0.2
#define tax3 0.25
int main(void)
{
	float T,hours, money, tax, input;
	char ch;
	while (1) 
	{
		printf("�����빤�ʵȼ�\n");
		printf("1) $8.75/hr         2) $9.33/hr\n");
		printf("3) $10.00/hr        3) $11.20/hr\n");
		printf("5) $quit\n");
		while ((ch = getchar()) == '\n')
		{
			continue;
		}
		if (ch> '0' && ch < '5')
		{
			switch (ch)
			{
			case '1':T = A;
				break;
			case '2':T = B;
				break;
			case '3':T = C;
				break;
			case '4':T = D;
				break;
			default:break;
			}
			printf("�����빤��Сʱ��\n");
			scanf("%f", &hours);
			if (hours >= 0)
			{
				if (hours <= 40)
				{
					money = hours*T;
					if (money <= 300)
					{
						tax = money*tax1;
					}
					else
					{
						tax = 300 * tax1 + (money - 300)*tax2;
					}
					input = money - tax;
				}
				else
				{
					hours = 40 + (hours - 40)*1.5;
					money = hours*T;
					if (money <= 450)
					{
						tax = 300 * tax1 + (money - 300)*tax2;
					}
					else
					{
						tax = 300 * tax1 + 150 * tax2 + (money - 450)*tax3;
					}
					input = money - tax;
				}
				printf("�����ܶ�Ϊ%f��˰��Ϊ%f��������Ϊ%f\n", money, tax, input);
			}
			else
			{
				printf("����������ȷ\n");
			}
		}
		else if (ch == '5')
		{
			break;
		}
		else
		{
			printf("��������ȷ���\n");
		}
	}
	getchar();
	return 0;
}