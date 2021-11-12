#include<stdio.h>
#include"aba.h"
extern int ok(void);
extern int a;
extern bool c;
int main(void)
{
	printf("累计输入两次1就结束\n");
	while (c == false)
	{
		scanf_s("%d", &a);
		getchar();
		ok();
	}
	printf("ok");
	getchar();
	return 0;
}