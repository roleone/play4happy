#include<stdio.h>
#define BS 40
#define JC 10.00
#define FR 300
#define XU 150
int main(void)
{
	float hours,money,tax,ok;
	printf("������һ�ܹ�����Сʱ��\n");
	scanf("%f", &hours);
	while (hours >= 0)
	{
		if (hours <= BS)
		{
			money = hours*JC;
			if (money <= 300)
			{
				tax = money*0.15;
			}
			else
			{
				tax = (money - 300)*0.2 + 300 * 0.15;
			}
			ok = money - tax;
		}
		else
		{
			hours = 30 + (hours - 30)*1.5;
			money = hours*JC;
			if (money <= 450)
			{
				tax = 300 * 0.15 + (money - 300)*0.2;
			}
			else
			{
				tax = 300 * 0.15 + 150 * 0.2 + (money - 450)*0.25;
			}
			ok = money - tax;
		}
		printf("�����ܶ�Ϊ%f��˰��Ϊ%f��������Ϊ%f��\n",money,tax,ok);
		scanf("%f", &hours);
	}
	getchar();
	return 0;
}