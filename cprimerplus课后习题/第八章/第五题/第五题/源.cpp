#include<stdio.h>
int main(void)
{
	int MAX, MIN;
	int guess;
	char ch, cr,kk;
	printf("��ʼ��(Y/N)\n");
	while ((kk = getchar()) != 'N')
	{
		MAX = 100, MIN = 0, guess = 50;
		while (getchar() != '\n')
			continue;
		if (kk == 'Y')
		{
			printf("1-100ѡһ���������y�ǲ¶��ˣ�n�ǲ´���\n");
			printf("��ģ��ǲ��� %d\n", guess);
			while ((ch = getchar()) != 'y')
			{
				while (getchar() != '\n')
					continue;
				if (ch == 'n')
				{
					printf("������y/n��\n");
					while (cr = getchar())
					{
						while (getchar() != '\n')
							continue;
						if (cr == 'y')
						{
							MAX = guess;
							guess = (guess + MIN) / 2;
							break;
						}
						else if (cr == 'n')
						{
							MIN = guess;
							guess = (guess + MAX) / 2;
							break;
						}
						else
						{
							printf("ɵ�ƣ�������y/n����ү���ºú��䣬y����n\n");
							continue;
						}
					}
					printf("�����Ҳ���%d�Բ��ԣ�y/n��\n", guess);
				}
				else
				{
					printf("ɵ�ƣ�������y/n����ү���ºú��䣬y����n\n");
					continue;
				}
			}
			while (getchar() != '\n')
				continue;
			printf("ү������\n");
			printf("�ʱʻ������ˣ�Y/N��\n");
		}
		else
		{
			printf("������ɶ�ˣ�������Y����������N\n");
		}
	}
	getchar();
	printf("�ʱ�");
	getchar();
	return 0;
}