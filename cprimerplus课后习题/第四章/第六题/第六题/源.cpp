#include<stdio.h>
#include<string.h>
int main()
{
	char name[20];
	char xing[20];
	printf("������������֣�\n");
	scanf_s("%s", name, sizeof(name));
	getchar();
	printf("����������գ�\n");
	scanf_s("%s",xing,sizeof(xing));
	getchar();
	printf("%s %s\n", name, xing);
	printf("%*zd %*zd\n", strlen(name), strlen(name),strlen(xing),strlen(xing));
	printf("%s %s\n", name, xing);
	printf("%-*zd %-*zd\n", strlen(name), strlen(name), strlen(xing), strlen(xing));
	getchar();
	return 0;
}