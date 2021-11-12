#include<stdio.h>
int main(void)
{
	char c;
	int n_a = 0, n_b=0, n_c=0;
	while ((c=getchar()) != '#')
	{
		n_c++;
		if (c == ' ')
		{
			n_a++;
			continue;
		}
		else if (c == '\n')
		{
			n_b++;
			continue; 
		}
	}
	getchar();
	printf("空格一共有%d 换行一共有%d 总字符有%d",n_a,n_b,n_c);
	getchar();
	return 0;
}