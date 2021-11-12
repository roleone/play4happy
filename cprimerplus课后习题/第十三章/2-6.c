#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	FILE*fp1;
	FILE*fp2;
	int count=0;
	char ch;
	char name1[20];
	char name2[20];
	printf("enter 2 filename:\n");
	scanf("%s%s",name1,name2);
	if((fp1=fopen(name1,"r"))==NULL)
	{
		fprintf(stderr,"open file1 wrong\n");
		exit(EXIT_FAILURE);
	}
	if((fp2=fopen(name2,"w"))==NULL)
	{
		fprintf(stderr,"open file2 wrong\n");
		exit(EXIT_FAILURE);
	}
	while((ch=getc(fp1))!=EOF)
	{
		if(count%3==0)
			putc(ch,fp2);
		count++;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
