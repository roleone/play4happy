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
	printf("大写字母%d个，小写字母%d个", ap_A, ap_a);
	getchar();
	return 0;
}