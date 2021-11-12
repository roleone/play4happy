#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	char tmp[5];
	size_t bytes;
	FILE*fp1;
	FILE*fp2;
	if(argc!=3)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	if(strcmp(argv[1],argv[2])==0)
	{
		fprintf(stderr,"dont enter same filename\n");
		exit(EXIT_FAILURE);
	}
	if((fp1=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	if((fp2=fopen(argv[2],"w"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	printf("fp1 %d,fp2 %d\n",ftell(fp1),ftell(fp2));
	while((bytes=fread(tmp,sizeof(char),5,fp1))>0)
	{
		fwrite(tmp,sizeof(char),bytes,fp2);
        	printf("fp1 %d,fp2 %d\n",ftell(fp1),ftell(fp2));
	}
	printf("fp1 %d,fp2 %d\n",ftell(fp1),ftell(fp2));
	fclose(fp1);
	fclose(fp2);
	return 0;
}
