#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 20
char* s_gets(char*,int);
int (*funcp)(const void*,const void*);
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int qsortBYAscii(const void*,const void*);
int qsortBYValue(const void*,const void*);
int main(void)
{
	struct book library[MAXBKS];
	int count=0;
	int index;
	printf("please enter the book title\n");
	printf("press enter at the start of the line to quit\n");
	while(count<MAXBKS&&s_gets(library[count].title,MAXTITL)!=NULL&&library[count].title[0]!='\0')
	{
		printf("now enter the author\n");
		s_gets(library[count].author,MAXAUTL);
		printf("now enter the value\n");
		scanf("%f",&library[count++].value);
		while(getchar()!='\n')
			continue;
		if(count<MAXBKS)
			printf("enter next book\n");
	}
	if(count>0)
	{
		printf("this is your book list:\n");
		for(index=0;index<count;index++)
			printf("%10s by %10s is $%.2f\n",library[index].title,library[index].author,library[index].value);
		funcp=qsortBYAscii;
		qsort(library,count,sizeof(struct book),funcp);
		printf("this is your books by ascii\n");
		for(index=0;index<count;index++)
			printf("%10s by %10s is $%.2f\n",library[index].title,library[index].author,library[index].value);
		funcp=qsortBYValue;
		qsort(library,count,sizeof(struct book),funcp);
		printf("this is your book by value\n");
		for(index=0;index<count;index++)
			printf("%10s by %10s is $%.2f\n",library[index].title,library[index].author,library[index].value);
	}
	else
		printf("no books ,too bad\n");
	return 0;
}
int qsortBYAscii(const void*a,const void*b)
{
	if(strcmp(((struct book*)a)->title,((struct book*)b)->title)>0)
		return 1;
	else
		return 0;
}
int qsortBYValue(const void*a,const void*b)
{
	if(((struct book*)a)->value>((struct book*)b)->value)
		return 1;
	else
		return 0;
}
char* s_gets(char* st,int n)
{
	int i=0;
	char *kk;
	kk=fgets(st,n,stdin);
	if(kk)
	{
		while(st[i]!='\n'&&st[i]!='\0')
			i++;
		if(st[i]=='\n')
			st[i]='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return kk;
}
