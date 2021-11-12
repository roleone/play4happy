#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	bool EI = true;
	int num = 0;
	char c_a, c_b='\n';
	while ((c_a = getchar()) != '#')
	{
		if (c_a == '\n')
			continue;
		if (c_b == 'e'&&c_a == 'i')
			num++;
		c_b = c_a;
	}
	getchar();
	printf("%d", num);
	getchar();
	return 0;
}