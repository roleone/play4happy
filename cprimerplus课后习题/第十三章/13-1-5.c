#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int check(char,char*);
int main(int argc,char *argv[])
{
	char tmp[256];
	FILE *fp;
	if(argc!=3)
	{
		fprintf(stderr,"enter wrong");
		exit(EXIT_FAILURE);
	}
	char ch=argv[1][0];
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		fprintf(stderr,"open wrong");
		exit(EXIT_FAILURE);
	}
	while(fgets(tmp,256,fp)!=NULL)
		if(check(ch,tmp))
			fputs(tmp,stdout);
	fclose(fp);
	return 0;
}
int check(char ch,char *ct)
{
	while(*ct)
		if(ch==*ct++)
			return (1);
	return 0;
}
