#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main(void)
{
	char ch;
	bool bk = true;
	int n=0, n1=0, n2=0, n3=0, n4=0;
	while ((ch = getchar()) != EOF)
	{
		if (isblank(ch))
			bk = true;
		if (isupper(ch))
		{
			n1++;
			if (bk == true)
			{
				bk = false;
				n++;
			}
		}
		if (islower(ch))
		{
			n2++;
			if (bk == true)
			{
				bk = false;
				n++;
			}
		}
		if (ispunct(ch))
		{
			n3++;
			if (bk == true)
			{
				bk = false;
				n++;
			}
		}
		if (isdigit(ch))
		{
			n4++;
			if (bk == true)
			{
				bk = false;
				n++;
			}
		}
	}
	printf("单词%d个，大写%d个，小写%d个，标点%d个，数字%d个",n,n1,n2,n3,n4);
	getchar();
	return 0;
}