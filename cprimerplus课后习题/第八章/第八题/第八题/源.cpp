#include<stdio.h>
int main(void)
{
	char ch;
	float num_1, num_2,num_3;
	while (1)
	{
		printf("Enter thr operation of your choice\n");
		printf("a.add          s.subtract\n");
		printf("m.multiply     d.divide\n");
		printf("q.quit\n");
		ch = getchar();
		while (getchar() != '\n')
			continue;
		if (ch == 'a' || ch == 's' || ch == 'm' || ch == 'd')
		{
			printf("�����������������֣�\n");
			while (1)
			{
				while (1)
				{
					if (scanf("%f%f", &num_1, &num_2) != 2)
					{
						printf("���������룺\n");
						while (getchar() != '\n')
							continue;
						continue;
					}
					else
					{
						break;
					}
				}
				if (ch == 'd'&&num_2 == 0)
				{
					printf("��������Ϊ0�����������룺\n");
				}
				else
					break;
			}
			switch (ch)
			{
			case 'a':num_3 = num_1 + num_2;
				break;
			case's':num_3 = num_1 - num_2;
				break;
			case 'm':num_3 = num_1*num_2;
				break;
			case 'd':num_3 = num_1 / num_2;
				break;
			default:
				break;
			}
			printf("���Ϊ%f\n", num_3);
			while (getchar() != '\n')
				continue;
		}
		else if (ch == 'q')
		{
			break;
		}
		else
		{
			printf("���������룺\n");
		}
	}
	printf("bye!");
	getchar();
	return 0;
}