#include<stdio.h>
#include<iostream>
void Invert(int n[], int num, int p, int b)
{
	int i,j,t;
	for (i = p - 1, j = p + b - 2; i < j; i++, j--)
	{
		t = n[i];
		n[i] = n[j];
		n[j] = t;
	}
}
int main()
{
	int n[30], b, p,num,i;
	printf("enter number of bits\n");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
		scanf("%d", &n[i]);
	printf("enter position u want to start and number of bits u want to invert\n");
	scanf("%d%d", &p, &b);
	printf("Before Inverting\n");
	for (i = 0; i < num; i++)
		printf("%d", n[i]);
	Invert(n, num, p, b);
	printf("\nAfter Inverting\n");
	for (i = 0; i < num; i++)
		printf("%d", n[i]);
	return 0;
}