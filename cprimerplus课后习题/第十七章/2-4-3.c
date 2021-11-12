#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"2-4.h"
#define min_per_hour 60
bool newcustomer(double);
Item customertime(long);
int main(void)
{
	Queue line1;
	Queue line2;
	Item ttmp1;
	Item ttmp2;
	int perhour1;
	int perhour2;
	int hours;
	int wait_time1;
	int wait_time2;
	long cycle;
	long cyclelimit;
	long turnaway1=0;
	long turnaway2=0;
	long customers1=0;
	long customers2=0;
	long served1=0;
	long served2=0;
	long sum_line1=0;
	long sum_line2=0;
	long line_wait1=0;
	long line_wait2=0;
	double min_per_cust1;
	double min_per_cust2;
	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand(time(0));
	puts("Case Study:Sigmund Lander'ss Advice Booth");
	puts("enter the number of simulation hours");
	scanf("%d",&hours);
	cyclelimit=hours*min_per_hour;
	puts("enter how many customers per hour1");
	scanf("%d",&perhour1);
	puts("enter how many customers per hour2");
	scanf("%d",&perhour2);
	min_per_cust1=min_per_hour*1.0/perhour1;
	min_per_cust2=min_per_hour*1.0/perhour2;
	for(cycle=0;cycle<cyclelimit;cycle++)
	{
		if(newcustomer(min_per_cust1))
		{
			if(Queueisfull(&line1))
				turnaway1++;
			else
			{
				ttmp1=customertime(cycle);
				AddQueue(&line1,ttmp1);
				customers1++;
			}
		}
		if(wait_time1<=0&&!Queueisempty(&line1))
		{
			DeletQueue(&line1,&ttmp1);
			wait_time1=ttmp1.processtime;
			line_wait1+=cycle-ttmp1.arrive;
			served1++;
		}
		if(wait_time1>0)
			wait_time1--;
		sum_line1+=Queuecount(&line1);
		if(newcustomer(min_per_cust2))
		{
			if(Queueisfull(&line2))
				turnaway2++;
			else
			{
				ttmp2=customertime(cycle);
				AddQueue(&line2,ttmp2);
				customers2++;
			}
		}
		if(wait_time2<=0&&!Queueisempty(&line2))
		{
			DeletQueue(&line2,&ttmp2);
			wait_time2=ttmp2.processtime;
			line_wait2+=cycle-ttmp2.arrive;
			served2++;
		}
		if(wait_time2>0)
			wait_time2--;
		sum_line2+=Queuecount(&line2);
	}
	if(customers1>0)
	{
		printf("customers1 accepted:%ld\n",customers1);
		printf("customers1 served:%ld\n",served1);
		printf("customers1 turnaway:%ld\n",turnaway1);
		printf("average1 que size:%.2lf\n",1.0*sum_line1/cyclelimit);
		printf("average1 line wait:%.2lf\n",1.0*line_wait1/served1);
	}
	else
		puts("1 no customer");
	EmptyQueue(&line1);
	if(customers2>0)
	{
		printf("customers2 accepted:%ld\n",customers2);
		printf("customers2 served:%ld\n",served2);
		printf("customers2 turnaway:%ld\n",turnaway2);
		printf("average2 que size:%.2lf\n",1.0*sum_line2/cyclelimit);
		printf("average2 line wait:%.2lf\n",1.0*line_wait2/served2);
	}
	else
		puts("2 no customer");
	EmptyQueue(&line2);
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
