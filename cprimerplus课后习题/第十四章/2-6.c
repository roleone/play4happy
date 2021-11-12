#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player{
	int num;
	char fname[10];
	char lname[10];
	int games;
	int stum;
	int mis;
	int RBI;
	float per;
};
struct player*EM;
char*s_gets(char*,int);
void read(FILE*,struct player*);
void write(FILE*,struct player*);
int main(void)
{
	FILE *fp;
	char choose[6];
	struct player NB;
	EM=&NB;
	if((fp=fopen("2-6.txt","a+b"))==NULL)
	{
		fprintf(stderr,"open wrong\n");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		rewind(fp);
	        printf("read or write or quit?\n");
		s_gets(choose,6);
		if(strcmp(choose,"r")!=0&&strcmp(choose,"w")!=0&&strcmp(choose,"q")!=0)
		{
			printf("enter r or w or q\n");
			continue;
		}
		else if(strcmp(choose,"q")==0)
			break;
		switch(*choose)
		{
	        	case 'r':read(fp,EM);
				 break;
	        	case 'w':write(fp,EM);
		        	 break;
	        	default:
		        	 break;
		}
	}
	fclose(fp);
	return 0;
}
void read(FILE*st,struct player* one)
{
	struct player EN={
		-1,
		"0",
		"0",
		0,
		0,
		0,
		0,
	};
	int n;
	printf("enter the player number:\n");
	if(scanf("%d",&n)!=1)
	{
		fprintf(stderr,"enter wrong\n");
		exit(EXIT_FAILURE);
	}
	while(getchar()!='\n')
		continue;
	while(fread(one,sizeof(struct player),1,st)!=0)
	{
		if(one->num==n)
		{
			EN.num=one->num;
			strcpy(EN.fname,one->fname);
			strcpy(EN.lname,one->lname);
			EN.games+=one->games;
			EN.stum+=one->stum;
			EN.mis+=one->mis;
			EN.RBI+=one->RBI;
		}
	}
	if(EN.num==-1)
		printf("none\n");
	else
		printf("%d %s.%s played %d games,stum %d,mistake %d RBI %d,per is %f\n",EN.num,EN.fname,EN.lname,EN.games,EN.stum,EN.mis,EN.RBI,(1.0*EN.stum)/EN.games);
}
void write(FILE*st,struct player* one)
{
	printf("enter the player number:\n");
	scanf("%d",&(one->num));
	while(getchar()!='\n')
		continue;
	printf("enter first name:\n");
	s_gets(one->fname,10);
	printf("enter last name:\n");
	s_gets(one->lname,10);
	printf("enter games,stum,mistake,RBI:\n");
	scanf("%d%d%d%d",&(one->games),&(one->stum),&(one->mis),&(one->RBI));
	while(getchar()!='\n')
		continue;
	fwrite(one,sizeof(struct player),1,st);
}
char*s_gets(char*st,int n)
{
	char*kk,*kz;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		if(kz=strchr(st,'\n'))
			*kz='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return kk;
}
