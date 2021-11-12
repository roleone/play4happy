#include<stdio.h>
int main(void)
{
	int a, b=5,c;
	char ch;
	printf("请输入一个大写字母\n");
	scanf("%c", &ch);
	getchar();
	while ('A'<=ch&&ch<='Z')
	{
		for (a = 0; a<b; a++)
		{
			for (c=1; c<b-a; c++)
			{
				printf(" ");
			}
			for (c = 0; c <= a; c++)
			{
				printf("%c",(int)ch-(4-c));
			}
			for (c=0;c<a;c++)
			{
				printf("%c", (int)ch-(5-a)-c);
			}
			for (c = 1; c < b-a; c++)
			{
				printf(" ");
			}
			printf("\n");
		}
		scanf("%c", &ch);
		getchar();
	}
	return 0;
}