#include<stdio.h>
#include"aba.h"
extern int ok(void);
extern int a;
extern bool c;
int main(void)
{
	printf("�ۼ���������1�ͽ���\n");
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