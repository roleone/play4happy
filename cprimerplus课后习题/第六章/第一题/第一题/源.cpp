#include<stdio.h>
int main(void)
{
	char ch[26];
	int a;
	const int b = 26;
	for (a = 0; a < b; a++)
	{
		ch[a] = ('a' + a);
		printf("%c", ch[a]);
	}
	getchar();
	return 0;
}