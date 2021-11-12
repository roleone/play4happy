#include<stdio.h>
#include<string.h>
int main(void)
{
	const char * st;
	st=strchr("abcdeaa", 97);
	printf("%c", *st);
	getchar();
	return 0;
}