#include<stdio.h>
#define A 2.05
#define B 1.15
#define C 1.09
int main(void)
{
	char ch_a,ch_b;
	float bon,bon_a=0,bon_b=0,bon_c=0,weight,money,get=0,press;
	printf("开始购物?（Y/N）\n");
	while ((ch_a=getchar())=='Y')
	{
		weight = 0;
		money = 0;
		while(1)
		{
			printf("请选择种类：\n");
			printf("a)洋葱（2.05元）    b)甜菜（1.15元）\n");
			printf("c)胡萝卜（1.09元）  p)退出选项\n");
			while ((ch_b = getchar()) == '\n')
				continue;
			if (ch_b>= 'a'&&ch_b <= 'c')
			{
				switch (ch_b)
				{
				case 'a':
					printf("请输入洋葱的磅数：\n");
					scanf("%f", &bon);
					bon_a += bon;
					break;
				case 'b':
					printf("请输入甜菜的磅数：\n");
					scanf("%f", &bon);
					bon_b += bon;
					break;
				case 'c':
					printf("请输入胡萝卜的磅数：\n");
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
				printf("请重新输入正确选项\n");
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
		printf("总重量为:%f,蔬菜费用为:%f,折扣为:%f,运费为:%f,总费用为:%f\n",bon,money,get,press,money+press);
		printf("开始购物?（Y/N）\n");
	}
	getchar();
	return 0;
	getchar();
}