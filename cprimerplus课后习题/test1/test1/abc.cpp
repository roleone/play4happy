#include<stdio.h>
int ko(void);
int a,b;
int kkp();
bool k = false;
int main(void)
{
	ko();
	return 0;
}
int kkp(void)
{
	k = true;
	return 0;
}
int ko(void)
{
	extern int ok(void);
	b = 0;
	printf("many xinacheng\n");
	while (b <= 3)
	{
		scanf_s("%d", &a);
		if (a == 1)
		{
			b++;
		}
		if (b == 2)
		{
			kkp();
		}
		getchar();
	}
	printf("ok");
	getchar();
	return 0;
}

