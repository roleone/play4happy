#include<stdio.h>
int main(void)
{
	int num,n_1=0,n_2=0,num_1=0,num_2=0;
	scanf("%d", &num);
	while (num != 0)
	{
		if (num % 2 == 0)
		{
			n_2++;
			num_2 += num;
		}
		else
		{
			n_1++;
			num_1 += num;
		}
		scanf("%d", &num);
	}
	getchar();
	printf("ż��������%d ƽ��ֵΪ%f ����������%d ƽ��ֵΪ%f ",n_2,1.0*num_2/n_2,n_1,1.0*num_1/n_1);
	getchar();
	return 0;
}