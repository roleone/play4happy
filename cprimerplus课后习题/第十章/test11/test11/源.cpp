#include<stdio.h>
int main(void)
{
	int zippo[4][2] = { {1,2} ,{3,4}, {5,6}, {7,8} };
	printf("zippo[0]��ַΪ%p,zippo[0]��ֵΪ%p\n", &zippo[0], zippo[0]);
	printf("zippo[0][0]�ĵ�ַΪ%p\n", &zippo[0][0]);
	int a[4];
	printf("%p %p %p", a,&a[0],&a);
	getchar();
	getchar();
	return 0;
}