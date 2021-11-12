#include<stdio.h>
int main()
{
	int asc;
	printf("请输入一个ASCII码值\n");
	scanf_s("%d", &asc);
	getchar();
	printf("%c", asc);
	getchar();
	return 0;
}