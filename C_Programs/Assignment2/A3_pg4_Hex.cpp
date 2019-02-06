#include<stdio.h>
char* BinToHex(char bin[])
{
	
}
char* HexToBin(char hex[])
{
	int i,j=0;
	char bin[100];
	for (i = 0; hex[i] != '\0'; i++)
	{
		b
	}
}
int main()
{
	long int bin, r, i, j = 0;
	int hex[16] = { 0, 1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111 };
	char h[10];
	printf("enter binary number\n");
	scanf("%ld", &bin);
	while (bin > 0)
	{
		r = bin % 10000;
		//	printf("%d\n", r);
		for (i = 0; i < 16; i++)
		{
			if (r == hex[i])
			{
				if (i < 10)
					h[j] = i + 48;
				else
					h[j] = i + 55;
				break;
			}
		}
		j++;
		bin = bin / 10000;
	}
	h[j] = '\0';
	return 0;
}