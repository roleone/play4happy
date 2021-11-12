#include<stdio.h>
#include<string.h>
int main(void)
{
	char name[20];
	printf("aaa\n");
	scanf_s("%s", name, sizeof(name));
	getchar();
	printf("%zd %zd", sizeof name, strlen(name));
	getchar();
}