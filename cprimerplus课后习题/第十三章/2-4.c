#include<stdio.h>
#include<stdlib.h>
int main(int argc,char*argv[])
{
	FILE*fp;
	int i=1;
	char tmp[256];
	while(i<argc)
	{
		if((fp=fopen(argv[i],"r"))==NULL)
		{
			fprintf(stderr,"open wrong\n");
			exit(EXIT_FAILURE);
		}
		while(fgets(tmp,256,fp)!=NULL)
			fputs(tmp,stdout);
		fclose(fp);
		i++;
	}
	return 0;
}
