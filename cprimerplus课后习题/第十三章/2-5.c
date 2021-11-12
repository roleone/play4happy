#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
	FILE*fp1;
	FILE*fp2;
	char tmp[256];
	int i=2;
	if((fp1=fopen(argv[1],"a"))==NULL)
	{
		fprintf(stderr,"open write wrong\n");
		exit(EXIT_FAILURE);
	}
	while(i<argc)
	{
		if((fp2=fopen(argv[i],"r"))==NULL)
		{
			fprintf(stderr,"open read %s wrong\n",argv[i]);
			exit(EXIT_FAILURE);
		}
		while(fgets(tmp,256,fp2)!=NULL)
			fputs(tmp,fp1);
		if(ferror(fp2)||ferror(fp1))
		{
			fprintf(stderr,"read or write wrong\n");
			exit(EXIT_FAILURE);
		}
		fclose(fp2);
		i++;
	}
	fclose(fp1);
	return 0;
}
