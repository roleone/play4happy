#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main(void)
{
	char ch,fd='\40';
	int n_1=0,n_2=0;
	bool k=false;
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch) && !isalpha(fd))
		{
			k = true;
			n_2++;
		}
		if (!isalpha(ch) && isalpha(fd))
			k = false;
		if (isalpha(ch)&&k == true)
			n_1++;
		fd = ch;
	}
	printf("平均每个单词%f个字母", n_1*1.0 / n_2);
	getchar();
	return 0;
}