#include<stdio.h>
#include<string.h>
int main(void)
{
	char name[20];
	printf("ÇëÊä³öÃû×Ö:\n");
	scanf_s("%s", name, sizeof(name));
	getchar();
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("%*s\n", strlen(name) + 3, name);
	getchar();
	return 0;
}