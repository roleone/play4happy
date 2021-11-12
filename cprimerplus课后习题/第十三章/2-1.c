#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE *fp;
	char ch;
	int n=0;
	char filename[50];
	printf("enter a file name:\n");
	scanf("%s",filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	while((ch=getc(fp))!=EOF)
	{
		putc(ch,stdout);
		n++;
	}
	fclose(fp);
	printf("%s have %d words\n",filename,n);
	return 0;
}
