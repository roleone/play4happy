#include<stdio.h>
#include<stdlib.h>
int main(int agrc,char * agrv[])
{
	double db[10];
	double num,nn;
	int n=1;
	for(int i=0;i<10;i++)
		db[i]=0;
	if(agrc>2)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	else if(agrc==1)
	{
		for(int i=0;i<10&&scanf("%lf",db+i)==1;i++)
			continue;
		while(getchar()!='\n')
			continue;
	}
	else
	{
	        FILE *fp;
		int k=0;
		if((fp=fopen(agrv[1],"rb"))==NULL)
		{
			fprintf(stderr,"open false\n");
			exit(EXIT_FAILURE);
		}
        	k=fread(db,sizeof(double),10,fp);
        	if(ferror(fp)!=0)
        	{
	        	fprintf(stderr,"read wrong\n");
		        exit(EXIT_FAILURE);
        	}
		printf("%d\n",k);
        	fclose(fp);
	}
	for(int i=0;i<10&&db[i]!='\0';i++)
	{
		num+=db[i];
		n=i;
	}
	nn=num/(n+1);
	printf("the per is %lf\n",nn);
	return 0;
}
