#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,a;
	char ch[255];
	printf("ÊäÈëÒ»ĞĞ×Ö·û\n");
	scanf("%s", ch);
	getchar();
	n = strlen(ch);
	for (a = 0; a < n; a++)
	{
		printf("%c", ch[n - 1 - a]);
	}
	getchar();
	return 0;
}