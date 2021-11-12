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
		printf("请输入类型：\n");
		printf("1)单身        2）户主\n");
		printf("3)已婚，共有   4）已婚离异\n");
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
				printf("请输入金额：\n");
				scanf("%f", &money);
				if (money <= line)
				{
					tax = money*0.15;
				}
				else
				{
					tax = line*0.15 + (money - line)*0.28;
				}
				printf("应缴纳%f\n", tax);
			}
			else
			{
				printf("请输入正确选项\n");
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