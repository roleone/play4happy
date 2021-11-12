#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int nop[20][30];
	char tmp[20][31];
	FILE*fp;
	if((fp=fopen("2-12-1.txt","r"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<30;j++)
			fscanf(fp,"%d",nop[i]+j);
		for(int j=0;j<30;j++)
			tmp[i][j]=48+nop[i][j];
		tmp[i][30]='\0';
	}
	fclose(fp);
	if((fp=fopen("2-12-2.txt","w"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	for (int i=0;i<20;i++)
	{
		for(int j=0;j<30;j++)
		{
			switch(tmp[i][j])
			{
				case '0':tmp[i][j]=' ';
					 break;
				case '1':tmp[i][j]='=';
					 break;
				case '2':tmp[i][j]='@';
					 break;
				case '3':tmp[i][j]='#';
					 break;
				case '4':tmp[i][j]='$';
					 break;
				case '5':tmp[i][j]='^';
					 break;
				case '6':tmp[i][j]='&';
					 break;
				case '7':tmp[i][j]='*';
					 break;
				case '8':tmp[i][j]='~';
					 break;
				case '9':tmp[i][j]='!';
					 break;
				default:break;
			}
		}
	}
	for(int i=0;i<20;i++)
	{
		fputs(tmp[i],fp);
		putc('\n',fp);
	}
	return 0;
}
