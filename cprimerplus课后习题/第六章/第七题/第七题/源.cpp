#include<stdio.h>
#include<string.h>
int main(void)
{
	char word[40];
	char ch;
	int num, a;
	printf("����һ������:\n");
	do
	{
		scanf("%s", word);
		getchar();
		num = strlen(word);
		for (a = 0; a<num; a++)
		{
			printf("%c", word[num - a - 1]);
		}
		printf("\n�Ƿ���� Y/N\n");
		scanf("%c", &ch);
		getchar();
	} while (ch == 'Y');
	return 0;
}