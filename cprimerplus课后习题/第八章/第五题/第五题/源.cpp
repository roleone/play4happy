#include<stdio.h>
int main(void)
{
	int MAX, MIN;
	int guess;
	char ch, cr,kk;
	printf("开始吗？(Y/N)\n");
	while ((kk = getchar()) != 'N')
	{
		MAX = 100, MIN = 0, guess = 50;
		while (getchar() != '\n')
			continue;
		if (kk == 'Y')
		{
			printf("1-100选一个记在心里，y是猜对了，n是猜错了\n");
			printf("妈的，是不是 %d\n", guess);
			while ((ch = getchar()) != 'y')
			{
				while (getchar() != '\n')
					continue;
				if (ch == 'n')
				{
					printf("大了吗（y/n）\n");
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
							printf("傻逼，让你输y/n，给爷重新好好输，y还是n\n");
							continue;
						}
					}
					printf("现在我猜是%d对不对（y/n）\n", guess);
				}
				else
				{
					printf("傻逼，让你输y/n，给爷重新好好输，y还是n\n");
					continue;
				}
			}
			while (getchar() != '\n')
				continue;
			printf("爷就晓得\n");
			printf("彩笔还来不了（Y/N）\n");
		}
		else
		{
			printf("让你输啥了，继续是Y，不来了是N\n");
		}
	}
	getchar();
	printf("彩笔");
	getchar();
	return 0;
}