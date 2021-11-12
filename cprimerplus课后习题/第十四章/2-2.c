#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
	int year,day,i,all=0,mon;
	char month[4];
	struct daydayyearyear {
		char monthes[4];
		int days;
		int monthnum;
	};
	struct daydayyearyear em[12]={
		{"Jan",31},
		{"Feb",28},
		{"Mar",31},
		{"Apr",30},
		{"May",31},
		{"Jun",30},
		{"Jul",31},
		{"Aug",31},
		{"Sep",30},
		{"Oct",31},
		{"Nov",30},
		{"Dec",31},
	};
	printf("please enter the year:\n");
	scanf("%d",&year);
	if(year%4==0)
		em[1].days=29;
	printf("please enter the month:\n");
	if(scanf("%d",&mon)==1)
		i=mon-1;
	else if(scanf("%s",month)==1)
	{
		for(i=0;i<12;i++)
        	{
	        	if(strcmp(month,em[i].monthes)==0)
				break;
	        	if(i==12&&strcmp(month,em[i].monthes)!=0)
	         	{
		        	fprintf(stderr,"enter month wrong\n");
		          	exit(EXIT_FAILURE);
	        	}
         	}
		while(getchar()!='\n')
			continue;
	}
	printf("please enter the day:\n");
	if(scanf("%d",&day)!=1||day<0||day>em[i].days)
	{
		fprintf(stderr,"enter day wrong\n");
		exit(EXIT_FAILURE);
	}
	for(int k=0;k<i;k++)
		all+=em[k].days;
	all+=day;
	printf("%d\n",all);
	em[1].days=28;
	all=0;
	return 0;
}
