#include<stdio.h>
#include<ctype.h>
#include<string.h>
int location(char);
int main(void)
{
	char ch='\0';
	char k[100];
	int n,p,a;
	printf("ÊäÈëÒ»×é×Ö·û\n");
	while (1)
	{
		if (ch != '#')
		{
			scanf("%s", k);
			p = strlen(k);
			for (a = 0; a < p; a++)
			{
				if ((ch = k[a]) != '#')
				{
					n = location(ch);
					if (n != -1)
						printf("%c  %d\n", ch, n);
					else
						printf("%d\n", n);
				}
				else
					break;
			}
		}
		else
			break;
	}
	while (getchar() != '\n')
		continue;
	getchar();
	return 0;
}
int location(char ch)
{
	if (islower(ch))
		return (int)ch - 96;
	else if (isupper(ch))
		return (int)ch - 64;
	else
		return -1;
}