#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"2-4.h"
#define min_per_hour 60
bool newcustomer(double);
Item customertime(long);
int main(void)
{
	Queue line;
	Item ttmp;
	int perhour;
	int hours;
	int wait_time;
	long cycle;
	long cyclelimit;
	long turnaway=0;
	long customers=0;
	long served=0;
	long sum_line=0;
	long line_wait=0;
	double min_per_cust;
	InitializeQueue(&line);
	srand(time(0));
	puts("Case Study:Sigmund Lander'ss Advice Booth");
	puts("enter the number of simulation hours");
	scanf("%d",&hours);
	cyclelimit=hours*min_per_hour;
	puts("enter how many customers per hour");
	scanf("%d",&perhour);
	min_per_cust=min_per_hour*1.0/perhour;
	for(cycle=0;cycle<cyclelimit;cycle++)
	{
		if(newcustomer(min_per_cust))
		{
			if(Queueisfull(&line))
				turnaway++;
			else
			{
				ttmp=customertime(cycle);
				AddQueue(&line,ttmp);
				customers++;
			}
		}
		if(wait_time<=0&&!Queueisempty(&line))
		{
			DeletQueue(&line,&ttmp);
			wait_time=ttmp.processtime;
			line_wait+=cycle-ttmp.arrive;
			served++;
		}
		if(wait_time>0)
			wait_time--;
		sum_line+=Queuecount(&line);
	}
	if(customers>0)
	{
		printf("customers accepted:%ld\n",customers);
		printf("customers served:%ld\n",served);
		printf("customers turnaway:%ld\n",turnaway);
		printf("average que size:%.2lf\n",1.0*sum_line/cyclelimit);
		printf("average line wait:%.2lf\n",1.0*line_wait/served);
	}
	else
		puts("no customer");
	EmptyQueue(&line);
	puts("bye");
	return 0;
}
bool newcustomer(double X)
{
	if(rand()*X/RAND_MAX<1)
		return true;
	else
		return false;
}
Item customertime(long when)
{
	Item iitmp;
	iitmp.processtime=rand()%3+1;
	iitmp.arrive=when;
	return iitmp;
}
