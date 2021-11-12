#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 11
char*s_gets(char*,int);
long doublemi(int);
bool check(char*,int);
bool check_two(char**,int,char*);
int hmbit(char*);
bool onlyone(char*,char*);
void kp(char*,int*,int);
int main(void)
{
	int l;
	char*ch,*ct;
	char tmp[MAX];
	int n;
	int num=1;
	printf("enter a series comb\n");
	s_gets(tmp,MAX);
	n=strlen(tmp);
	int kkp[n];
	char*temp[doublemi(n)];
	temp[0]=(char*)malloc(n+1);
	strcpy(temp[0],tmp);
	printf("enter a next(q to quit):\n");
	for(int i=1;i<doublemi(n)&&s_gets(tmp,MAX)!=NULL&&check(tmp,n);i++)
	{
		if(check_two(temp,i,tmp)==false)
		{
			printf("there is the one\n");
			i--;
			continue;
		}
		temp[i]=(char*)malloc(n+1);
		strcpy(temp[i],tmp);
		num=i+1;
		printf("enter a next(q to quit):\n");
	}
	for(int p=0;p<num;p++)
	{
		for(int q=0;q<n;q++)
		{
			printf("%c",'A'+q);
			printf("%c",temp[p][q]=='0'?'\'':'\0');
		}
		if(p!=num-1)
			putchar('+');
		if(p==num-1)
			putchar('=');
	}
	for(int z=0;z<n;z++)
	{
		for(int p=0;p<num;p++)
		{
			for(int q=1;q<num-p;q++)
			{
				if(hmbit(temp[p])-hmbit(temp[p+q])==1||hmbit(temp[p])-hmbit(temp[p+q])==-1)
				{
					if(onlyone(temp[p],temp[p+q]))
					{
						l=0;
					while((ch=strchr(temp[p]+l,'1'))-temp[p]==(ct=strchr(temp[p+q]+l,'1'))-temp[p+q])
						l=ch-temp[p]+1;
					if((ch!=NULL&&ch-temp[p]<ct-temp[p+q])||ct==NULL)
					{
						*ch='X';
						*(temp[p+q]+(ch-temp[p]))='X';
					}
					else
					{
						*ct='X';
						*(temp[p]+(ct-temp[p+q]))='X';
					}
					}
				}
			}
		}
		for(int q=1;q<num;q++)
		{
			for(int p=0;p<q;p++)
			{
				if(strcmp(temp[q],temp[p])==0)
				{
					free(temp[q]);
					for(int j=q+1;j<num;j++)
						temp[j-1]=temp[j];
					q--;
					num--;
					break;
				}
			}
		}
	}
	for(int p=0;p<num;p++)
	{
		kp(temp[p],kkp,n);
		for(int q=1;q<num-p;q++)
		{
			for(int r=0;r<n;r++)
			{
				if(kkp[r]==0&&temp[p][r]!=temp[p+q][r])
					break;
				if(r==n-1)
				{
					free(temp[p+q]);
					for(int j=p+q+1;j<num;j++)
						temp[j-1]=temp[j];
					q--;
					num--;
				}
			}
		}
	}
	for(int p=0;p<num;p++)
	{
		for(int q=0;q<n;q++)
		{
			printf("%c",temp[p][q]=='X'?'\0':'A'+q);
			printf("%c",temp[p][q]=='0'?'\'':'\0');
		}
		if(p!=num-1)
			putchar('+');
		if(p==num-1)
			putchar('\n');
		free(temp[p]);
	}
	return 0;
}
long doublemi(int n)
{
	long k=1;
	for(int j=0;j<n;j++)
		k*=2;
	return k;
}
char*s_gets(char*st,int n)
{
	char*kk,*kt;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		if(kt=strchr(st,'\n'))
			*kt='\0';
		else
			while(getchar()!='\n');
	}
	return kk;
}
bool check(char*st,int k)
{
	for(int j=0;j<k;j++)
	{
		if(st[j]!='0'&&st[j]!='1')
			return false;
	}
	return true;
}
bool check_two(char**ts,int j,char*kt)
{
	for(int p=0;p<j;p++)
	{
		if(strcmp(ts[p],kt)==0)
			return false;
	}
	return true;
}
int hmbit(char*st)
{
	int k=0;
	char kt='1';
	char kk[MAX];
	char *km;
	strcpy(kk,st);
	while(km=strchr(kk,kt))
	{
		*km='0';
		k++;
	}
	return k;
}
bool onlyone(char*st,char*sk)
{
	char ttmp[MAX];
	char tmmp[MAX];
	char* ttmpp;
	char* tmmpp;
	strcpy(ttmp,st);
	strcpy(tmmp,sk);
	while((ttmpp=strchr(ttmp,'1'))-ttmp==(tmmpp=strchr(tmmp,'1'))-tmmp)
	{
		*ttmpp='0';
		*tmmpp='0';
	}
	if((ttmpp!=NULL&&ttmpp-ttmp<tmmpp-tmmp)||tmmpp==NULL)
		*ttmpp='0';
	else
		*tmmpp='0';
	if(strcmp(ttmp,tmmp)==0)
		return true;
	else
		return false;
}
void kp(char*kp1,int*kp2,int k)
{
	for(int j=0;j<k;j++)
		kp2[j]=0;
	char*tmpp;
	char ttmp[MAX];
	strcpy(ttmp,kp1);
	for(int j=0;j<k&&(tmpp=strchr(ttmp,'X'))!=NULL;j++)
	{
		*tmpp='0';
		kp2[tmpp-ttmp]=1;
	}
}
