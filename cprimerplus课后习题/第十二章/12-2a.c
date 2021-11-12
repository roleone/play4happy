#include<stdio.h>
#include"12-2a.h"
static int mode;
void get_info(void)
{
	if(mode==0)
	{
        	printf("Enter distance traveled in kilometers:");
        	scanf("%d",&kilo);
	        printf("Enter fuel consumed in liters:");
        	scanf("%f",&fuel);
	}
	else
	{

        	printf("Enter distance traveled in miles:");
        	scanf("%d",&mile);
	        printf("Enter fuel consumed in gallon:");
        	scanf("%f",&gall);
	}
}
void show_info(void)
{
	if(mode==0)
        	printf("Fuel consumption is %f liters per 100 km.\n",fuel/kilo*100);
	else
		printf("Fuel consumption is %f miles per gallon.\n",mile/gall);
}
void set_mode(int n)
{
	if(n>1)
	{
		printf("Invalid mode specified.Mode 1(US) used.\n");
		mode=1;
	}
	if(n==0)
		mode=0;
	else
		mode=1;
}
