#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char*argv[])
{
	FILE*fp1;
	FILE*fp2;
	char tmp1[256];
	char tmp2[256];
	if(argc!=3)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	if((fp1=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr,"open file1 wrong\n");
		exit(EXIT_FAILURE);
	}
	if((fp2=fopen(argv[2],"r"))==NULL)
	{
		fprintf(stderr,"open file2 wrong\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(tmp1,256,fp1)!=NULL&&fgets(tmp2,256,fp2)!=NULL)
	{
		fputs(tmp1,stdout);
		fputs(tmp2,stdout);
	}
	rewind(fp1);
	rewind(fp2);
	while(fgets(tmp1,256,fp1)!=NULL&&fgets(tmp2,256,fp2)!=NULL)
	{
		char *ch=strchr(tmp1,'\n');
		*ch='\0';
		fprintf(stdout,"%s",tmp1);
		fprintf(stdout,"%s",tmp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
