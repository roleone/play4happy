#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
struct plant{
	int num;
	bool sign;
	char fname[10];
	char lname[10];
};
char*s_gets(char*,int);
int shownum(struct plant *);
void showlist(struct plant*);
void showalpha(struct plant*);
void add(struct plant*);
void delet(struct plant*);
int main(void)
{
	char ch;
	char ct;
	int z;
	struct plant fly[4][12]={
		{
			{1,false,"\0","\0"},
			{2,false,"\0","\0"},
			{3,false,"\0","\0"},
			{4,false,"\0","\0"},
			{5,false,"\0","\0"},
			{6,false,"\0","\0"},
			{7,false,"\0","\0"},
			{8,false,"\0","\0"},
			{9,false,"\0","\0"},
			{10,false,"\0","\0"},
			{11,false,"\0","\0"},
			{12,false,"\0","\0"}
		},
		{
			{1,false,"\0","\0"},
			{2,false,"\0","\0"},
			{3,false,"\0","\0"},
			{4,false,"\0","\0"},
			{5,false,"\0","\0"},
			{6,false,"\0","\0"},
			{7,false,"\0","\0"},
			{8,false,"\0","\0"},
			{9,false,"\0","\0"},
			{10,false,"\0","\0"},
			{11,false,"\0","\0"},
			{12,false,"\0","\0"}
		},
		{
			{1,false,"\0","\0"},
			{2,false,"\0","\0"},
			{3,false,"\0","\0"},
			{4,false,"\0","\0"},
			{5,false,"\0","\0"},
			{6,false,"\0","\0"},
			{7,false,"\0","\0"},
			{8,false,"\0","\0"},
			{9,false,"\0","\0"},
			{10,false,"\0","\0"},
			{11,false,"\0","\0"},
			{12,false,"\0","\0"}
		},
		{
			{1,false,"\0","\0"},
			{2,false,"\0","\0"},
			{3,false,"\0","\0"},
			{4,false,"\0","\0"},
			{5,false,"\0","\0"},
			{6,false,"\0","\0"},
			{7,false,"\0","\0"},
			{8,false,"\0","\0"},
			{9,false,"\0","\0"},
			{10,false,"\0","\0"},
			{11,false,"\0","\0"},
			{12,false,"\0","\0"}
		}
	};
	while(1)
	{
		printf("enter the fly:\n");
		printf("a)102 b)311 c)444 d)519 e)quit\n");
		ct=getchar();
		while(getchar()!='\n')
			continue;
		if(ct<'a'||ct>'e')
		{
			printf("enter a-e\n");
			continue;
		}
		if(ct=='e')
			break;
		switch(ct)
		{
			case 'a':z=0;
				break;
			case 'b':z=1;
				break;
			case 'c':z=2;
				break;
			case 'd':z=3;
				break;
			default:
				break;
		}
		while(1)
		{
			printf("To choose a function,enter its letter label:\n");
			printf("a) Show number of empty seat\n");
			printf("b) Show list of full seats\n");
			printf("c) Show alphabetical\n");
			printf("d) Assign a customer to a seat assignment\n");
			printf("e) Delete a seat assignment\n");
			printf("f) Quit\n");
			while((ch=getchar())<'a'||ch>'f')
			{
				while(getchar()!='\n')
					continue;
				printf("enter a~f\n");
			}
			while(getchar()!='\n')
				continue;
			if(ch=='f')
				break;
			switch(ch)
			{
				case 'a':shownum(fly[z]);
					break;
				case 'b':showlist(fly[z]);
					break;
				case 'c':showalpha(fly[z]);
					break;
				case 'd':add(fly[z]);
					break;
				case 'e':delet(fly[z]);
					break;
				default:
					break;
			}
		}
	}
	return 0;
}
int shownum(struct plant*ptr)
{
	int n=0;
	for(int i=0;i<12;i++)
		if((ptr+i)->sign==false)
		{
			printf("%d. ",(ptr+i)->num);
			n++;
		}
	putchar('\n');
}
void showlist(struct plant*ptr)
{
	for(int i=0;i<12;i++)
		if(ptr[i].sign==true)
			printf("%d.%d.%s.%s\n",ptr[i].num,ptr[i].sign,ptr[i].fname,ptr[i].lname);
}
void showalpha(struct plant*ptr)
{
	struct plant tmp;
	for(int i=0;i<11;i++)
	{
		for(int j=1;j<12-i;j++)
		{
			if(strcmp(ptr[i].fname,ptr[i+j].fname)>0)
			{	
				tmp=ptr[i];
				ptr[i]=ptr[i+j];
				ptr[i+j]=tmp;
			}
			else if(strcmp(ptr[i].fname,ptr[i+j].fname)==0)
			{
				if(strcmp(ptr[i].lname,ptr[i+j].lname)>0)
				{
					tmp=ptr[i];
					ptr[i]=ptr[i+j];
					ptr[i+j]=tmp;
				}
			}
		}
	}
	for(int i=0;i<12;i++)
		printf("%d.%d.%s.%s\n",ptr[i].num,ptr[i].sign,ptr[i].fname,ptr[i].lname);
}
void add(struct plant*ptr)
{
	int number;
	int k;
	printf("enter the num:\n");
	while(scanf("%d",&number)!=1||number>12||number<0)
		printf("enter 1-12\n");
	while(getchar()!='\n')
		continue;
	for(int i=0;i<12;i++)
		if(ptr[i].num==number)
			k=i;
	ptr[k].sign=true;
	printf("enter fname\n");
	s_gets(ptr[k].fname,10);
	printf("enter lname\n");
	s_gets(ptr[k].lname,10);
}
void delet(struct plant*ptr)
{
	int number;
	int k;
	printf("please enter a num\n");
	while(scanf("%d",&number)!=1||number<0||number>12)
		printf("please enter 1-12\n");
	while(getchar()!='\n')
		continue;
	for(int i=0;i<12;i++)
		if(ptr[i].num==number)
			k=i;
	ptr[k].num=number;
	ptr[k].sign=false;
	strcpy(ptr[k].fname,"\0");
	strcpy(ptr[k].lname,"\0");
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
