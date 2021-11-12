#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
	FILE*fp;
	char tmp[256];
	if(argc!=3)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	while(fgets(tmp,255,fp)!=NULL)
		if(strstr(tmp,argv[1]))
			fputs(tmp,stdout);
	fclose(fp);
	return 0;
}
