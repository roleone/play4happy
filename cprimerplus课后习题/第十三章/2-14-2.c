#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	double nop[20][30];
	char tmp[20][31];
	int num[20][30];
	FILE*fp;
	if((fp=fopen("2-14-1.txt","r"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<30;j++)
			fscanf(fp,"%lf",nop[i]+j);
	}
	fclose(fp);
	for(int i=0;i<20;i++)
	{
		if(i==0)
		{
			for(int j=0;j<30;j++)
			{
				if(j==0)
				{
					if(((nop[i][j]-nop[i+1][j])>1||(nop[i][j]-nop[i+1][j])<-1)&&((nop[i][j]-nop[i][j+1])>1||(nop[i][j]-nop[i][j+1]<-1)))
					{
						nop[i][j]=(nop[i][j]+nop[i+1][j]+nop[i][j+1])/3;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
				else if(j==29)
				{
					if(((nop[i][j]-nop[i+1][j])>1||(nop[i][j]-nop[i+1][j])<-1)&&((nop[i][j]-nop[i][j-1])>1||(nop[i][j]-nop[i][j-1]<-1)))
					{
						nop[i][j]=(nop[i][j]+nop[i+1][j]+nop[i][j-1])/3;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
				else
				{
					if(((nop[i][j]-nop[i][j-1])>1||(nop[i][j]-nop[i][j-1])<-1)&&((nop[i][j]-nop[i][j+1])>1||(nop[i][j]-nop[i][j+1])<-1)&&((nop[i][j]-nop[i+1][j])>1||(nop[i][j]-nop[i+1][j])<-1))
					{
						nop[i][j]=(nop[i][j]+nop[i+1][j]+nop[i][j-1]+nop[i][j+1])/4;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
			}
		}
		if(i==19)
		{
			for(int j=0;j<30;j++)
			{
				if(j==0)
				{
					if(((nop[i][j]-nop[i-1][j])>1||(nop[i][j]-nop[i-1][j])<-1)&&((nop[i][j]-nop[i][j+1])>1||(nop[i][j]-nop[i][j+1]<-1)))
					{
						nop[i][j]=(nop[i][j]+nop[i-1][j]+nop[i][j+1])/3;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
				else if(j==29)
				{
					if(((nop[i][j]-nop[i-1][j])>1||(nop[i][j]-nop[i-1][j])<-1)&&((nop[i][j]-nop[i][j-1])>1||(nop[i][j]-nop[i][j-1]<-1)))
					{
						nop[i][j]=(nop[i][j]+nop[i-1][j]+nop[i][j-1])/3;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
				else
				{
					if(((nop[i][j]-nop[i][j-1])>1||(nop[i][j]-nop[i][j-1])<-1)&&((nop[i][j]-nop[i][j+1])>1||(nop[i][j]-nop[i][j+1])<-1)&&((nop[i][j]-nop[i-1][j])>1||(nop[i][j]-nop[i-1][j])<-1))
					{
						nop[i][j]=(nop[i][j]+nop[i-1][j]+nop[i][j-1]+nop[i][j+1])/4;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
			}
		}
		else
		{
			for(int j=0;j<30;j++)
			{
				if(j==0)
				{
					if(((nop[i][j]-nop[i-1][j])>1||(nop[i][j]-nop[i-1][j])<-1)&&((nop[i][j]-nop[i+1][j])>1||(nop[i][j]-nop[i+1][j])<-1)&&((nop[i][j]-nop[i][j+1])>1||(nop[i][j]-nop[i][j+1])<-1))
					{
						nop[i][j]=(nop[i][j]+nop[i+1][j]+nop[i-1][j]+nop[i][j+1])/4;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
				else if(j==29)
				{
					if(((nop[i][j]-nop[i-1][j])>1||(nop[i][j]-nop[i-1][j])<-1)&&((nop[i][j]-nop[i+1][j])>1||(nop[i][j]-nop[i+1][j])<-1)&&((nop[i][j]-nop[i][j-1])>1||(nop[i][j]-nop[i][j-1])<-1))
					{
						nop[i][j]=(nop[i][j]+nop[i+1][j]+nop[i-1][j]+nop[i][j-1])/4;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
				else
				{
					if(((nop[i][j]-nop[i][j-1])>1||(nop[i][j]-nop[i][j-1])<-1)&&((nop[i][j]-nop[i][j+1])>1||(nop[i][j]-nop[i][j+1])<-1)&&((nop[i][j]-nop[i-1][j])>1||(nop[i][j]-nop[i-1][j])<-1)&&((nop[i][j]-nop[i+1][j])>1||(nop[i][j]-nop[i+1][j])<-1))
					{
						nop[i][j]=(nop[i][j]+nop[i-1][j]+nop[i+1][j]+nop[i][j-1]+nop[i][j+1])/5;
					}
						num[i][j]=(nop[i][j]+0.5)>((int)nop[i][j]+1)?(int)nop[i][j]+1:(int)nop[i][j];
				}
			}
		}
	}
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<30;j++)
			tmp[i][j]=48+num[i][j];
		tmp[i][30]='\0';
	}
	if((fp=fopen("2-14-2.txt","w"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<20;i++)
	{
		fputs(tmp[i],fp);
		putc('\n',fp);
	}
	fclose(fp);
	if((fp=fopen("2-14-3.txt","w"))==NULL)
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
	fclose(fp);
	return 0;
}
