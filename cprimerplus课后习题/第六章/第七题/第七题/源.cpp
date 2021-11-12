#include<stdio.h>
#include<string.h>
int main(void)
{
	char word[40];
	char ch;
	int num, a;
	printf("输入一个单词:\n");
	do
	{
		scanf("%s", word);
		getchar();
		num = strlen(word);
		for (a = 0; a<num; a++)
		{
			printf("%c", word[num - a - 1]);
		}
		printf("\n是否继续 Y/N\n");
		scanf("%c", &ch);
		getchar();
	} while (ch == 'Y');
	return 0;
}