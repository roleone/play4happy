#include<stdio.h>
int main(int argc,char*argv[])
{
	int i = 0;
	while (i < argc-1)
	{
		puts(argv[argc - 1 - i]);
		i++;
	}
	return 0;
}