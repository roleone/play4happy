#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
	FILE*fp;
	char tmp[6];
	char ch;
	int count;
	char *test;
	tmp[6]='\0';
	if(argc<2)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	else if(argc==2)
	{
		while(fscanf(stdin,"%c",&ch)==1&&ch!='\n')
		{
			if(ch==*argv[1])
				count++;
		}
		printf("stdin have %d %c\n",count,*argv[1]);
	}
	else
	{
		for(int i=2;i<argc;i++)
		{
			if((fp=fopen(argv[i],"r"))==NULL)
			{
				fprintf(stderr,"open %s wrong\n",argv[i]);
				continue;
			}
			while(fread(tmp,sizeof(char),5,fp)>0)
			{
		        	while(test=strchr(tmp,*argv[1]))
		         	{
					count++;
			        	if(*argv[1]=='a')
						*test='b';
					else
						*test='a';
		        	}
			}
			printf("%s have %d %c\n",argv[i],count,*argv[1]);
			count=0;
			fclose(fp);
		}
	}
	return 0;
}
