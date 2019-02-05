#include<stdio.h>
#include<math.h>
int main()
{
	int bin, s=0,d,r;
	printf("enter binary number\n");
	scanf("%d", &bin);
	while (bin > 0)
	{
		r = bin % 10;
		s = s * 2 + r;
		bin = bin / 10;
	}
	printf("%d", s);
	return 0;
}