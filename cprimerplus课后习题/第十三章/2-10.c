#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE*fp;
	int i;
	char file[30];
	char tmp[256];
	printf("enter a file name:\n");
	scanf("%s",file);
	if((fp=fopen(file,"r"))==NULL)
	{
		fprintf(stderr,"open file wrong\n");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		printf("enter a position:\n");
		if(scanf("%d",&i)!=1||i<0)
			break;
		fseek(fp,i-1,SEEK_SET);
		fgets(tmp,256,fp);
		fputs(tmp,stdout);
	}
	fclose(fp);
	return 0;
}
