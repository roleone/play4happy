#include<stdio.h>
#include<stdlib.h>
struct name{
	char fname[10];
	char iname[10];
	char lname[10];
};
struct numb{
	long shebao;
	struct name kb;
};
char *s_gets(char*,int);
void structprintf(struct numb);
int main(void)
{
	struct numb all[5]={{.shebao=0},{.shebao=0},{.shebao=0},{.shebao=0},{.shebao=0}};
	printf("enter shebao\n");
	for(int i=0;i<5&&scanf("%ld",&(all[i].shebao))==1;i++)
	{
		while(getchar()!='\n')
			continue;
		printf("fname\n");
		s_gets(all[i].kb.fname,10);
		printf("iname\n");
		s_gets(all[i].kb.iname,10);
		printf("lname\n");
		s_gets(all[i].kb.lname,10);
		if(i!=5)
			printf("enter shebao\n");
	}
	for(int i=0;i<5&&all[i].shebao!=0;i++)
		structprintf(all[i]);
	return 0;
}
char*s_gets(char*st,int n)
{
	int i=0;
	char*kk;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		while(st[i]!='\0'&&st[i]!='\n')
			i++;
		if(st[i]=='\n')
			st[i]='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return kk;
}
void structprintf(struct numb ab)
{
	printf("%s, %s %c.--%ld\n",ab.kb.lname,ab.kb.fname,*(ab.kb.iname),ab.shebao);
}
