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
	printf("�ո�һ����%d ����һ����%d ���ַ���%d",n_a,n_b,n_c);
	getchar();
	return 0;
}