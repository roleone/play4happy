#include<stdio.h>
int main(void)
{
	char name[20];
	char xing[20];
	printf("«Î ‰»Î√˚∫Õ–’\n");
	scanf_s("%s %s",name,sizeof(name), xing, sizeof(xing));
	getchar();
	printf("%s,%s",name,xing);
	getchar();
	return 0;
}