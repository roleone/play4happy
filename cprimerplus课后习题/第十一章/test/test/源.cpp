#include<stdio.h>
int main(void)
{
	char kk[2] = { '\0','e'};
	char n[5];
	putchar('c');
	putchar('\007');
	putchar('e');
	printf("w\0wd");
	puts(kk);
	putchar('\n');
	printf("%s  %p  %p  %c\n", "We", "We", &"we", *"We");
	scanf("%s", n);
	printf("%s", n);
	while (getchar() != '\n')
		continue;
	getchar();
	return 0;
}