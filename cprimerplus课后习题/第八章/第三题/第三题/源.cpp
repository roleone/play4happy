#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	int ap_A=0, ap_a=0;
	while ((ch = getchar()) != EOF)
	{
		if (islower(ch))
			ap_a++;
		if (isupper(ch))
			ap_A++;
	}
	printf("��д��ĸ%d����Сд��ĸ%d��", ap_A, ap_a);
	getchar();
	return 0;
}