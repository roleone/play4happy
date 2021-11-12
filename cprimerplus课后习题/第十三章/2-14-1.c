#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE*fp;
	if((fp=fopen("2-14-1.txt","w"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<30;j++)
			fprintf(fp,"%2d ",(i+j+1)*2%10);
		putc('\n',fp);
	}
	fclose(fp);
	return 0;
}
