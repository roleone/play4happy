#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
	int i=0,n,j;
	while(i<10)
	{
		srand(i);
		j=0;
		while(j<1000)
		{
			n=rand()%10+1;
			switch(n)
			{
				case 1:n1++;
				       break;
                        	case 2:n2++;
				       break;
				case 3:n3++;
				       break;
                        	case 4:n4++;
				       break;
				case 5:n5++;
				       break;
                        	case 6:n6++;
				       break;
				case 7:n7++;
				       break;
                        	case 8:n8++;
				       break;
				case 9:n9++;
				       break;
                        	case 10:n0++;
				       break;
			}
			j++;
		}
		printf("base on %d:\n1:%d,2:%d,3:%d,4:%d,5:%d,6:%d,7:%d,8:%d,9:%d,10:%d\n",i,n1,n2,n3,n4,n5,n6,n7,n8,n9,n0);
		i++;
		n1=n2=n3=n4=n5=n6=n7=n8=n9=n0=0;
	}
	return 0;
}
