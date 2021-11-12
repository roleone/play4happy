#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	FILE*fp1;
	FILE*fp2;
	int num;
	char words[41];
	if((fp1=fopen("2-9-1.txt","a+"))==NULL)
	{
		fprintf(stderr,"open 2-9-1.txt wrong\n");
		exit(EXIT_FAILURE);
	}
	if((fp2=fopen("2-9-2.txt","r+"))==NULL)
	{
		fprintf(stderr,"open 2-9-2.txt wrong\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fp2,"%5d",&num);
	printf("enter a word to add:(# to quit):\n");
	while(fscanf(stdin,"%40s",words)==1&&words[0]!='#')
	{
		fprintf(fp1,"%d.%s\n",num,words);
		num++;
	}
	rewind(fp2);
	fprintf(fp2,"%d",num);
	puts("file contents:\n");
	rewind(fp1);
	while(fscanf(fp1,"%40s",words)==1)
		puts(words);
	puts("DONE");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
