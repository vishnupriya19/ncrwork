#include<stdio.h>
#include<stdlib.h>
#include<string.h>//lnkn
int j;
int* HexToBin(char h[])
{
	int i;
	int *a = (int*)malloc(sizeof(int) * 35);
	char t;
	for (i = 0; h[i] != '\0'; i=i+1)
	{
		t = h[i];
		if ((t == '0') || (t == '1') || (t == '2') || (t == '3') || (t == '4') || (t == '5') || (t == '6') || (t == '7'))
			a[j++] = 0;
		else
			a[j++] = 1;
		t = h[i];
		if ((t == '0') || (t == '1') || (t == '2') || (t == '3') || (t == '8') || (t == '9') || (t == 'A') || (t == 'B'))
			a[j++] = 0;
		else
			a[j++] = 1;
		t = h[i];
		if ((t == '0') || (t == '1') || (t == '4') || (t == '5') || (t == '8') || (t == '9') || (t == 'C') || (t == 'D'))
			a[j++] = 0;
		else
			a[j++] = 1;
		t = h[i];
		if ((t == '0') || (t == '2') || (t == '4') || (t == '6') || (t == '8') || (t == 'A') || (t == 'C') ||(t=='E'))
			a[j++] = 0;
		else
			a[j++] = 1;

	}
	return a;
}
int* compliment(int a[])
{
	int i;
	int *b = (int*)malloc(sizeof(int) * 35);
	for (i = 0; i < j; i++)
	{
		if (a[i] == 0)
			b[i] = 1;
		else
			b[i] = 0;
	}
	return b;
}
char* BinToHex(int b[])
{
	char *s = (char*)malloc(sizeof(char) * 10);
	int k = 0, val, i;
	for(i = 0 ; i < j; i = i + 4)
	{
		val = (b[i] * 8) + (b[i + 1] * 4) + (b[i + 2] * 2) + (b[i + 3] * 1);
		if (val < 10)
			s[k++] = val + 48;
		else
			s[k++] = val + 55;
	}
	return s;
}
int* bitShift(int a[])
{
	int i,d,n;
	int *b = (int*)malloc(sizeof(int) * 35);
	printf("enter 1.right shift 2.left shift\n");
	scanf("%d", &d);
	printf("enter number of bits you want to shift\n");
	scanf("%d", &n);
	if (d == 1)
	{
		for (i = j - n - 1; i >= 0; i--)
		{
			b[i + n] = a[i];
		}
		for (i = 0; i < n; i++)
			b[i] = 0;
	}
	else
	{
		for (i = n ; i < j ; i++)
		{
			b[i - n] = a[i];
		}
		for (i = j-n; i < j; i++)
			b[i] = 0;
	}
	return b;
}
int* maskOp(int a[])
{
	int c,*pt1,i;
	char h[50];
	printf("enter choice 1.And 2.Or 3.Ex-Or");
	scanf("%d", &c);
	printf("enter another HexaDecimal value");
	scanf("%s", h);
	pt1 = HexToBin(h);
	printf("\n");
	printf("%d\n", j);
	for (i = 0; i < j; i++)
		printf("%d", *(pt1 + i));
	printf("\n");
	if (c == 1)
	{
		for (i = 0; i < j; i++)
		{
			if (a[i] == 1 && pt1[i] == 1)
				pt1[i] = 1;
			else
				pt1[i] = 0;
		}
	}
	else if (c == 2)
	{

	}
	else
	{

	}
	return pt1;
}
int main()
{
	char h[10],*s1,*s2,*s3,h1[10];
	int *a, i, *b, *c, *d, *pt1;
	int choice;
	printf("enter choice\n");
	scanf("%d", &choice);
	//printf("%d\n", choice);
	printf("enter a hexadecimal value");
	scanf("%s", h);
	a = HexToBin(h);
	for (i = 0; i < j; i++)
		printf("%d", *(a + i));
	printf("\n");
	if (choice == 1)
	{
		b = compliment(a);
		for (i = 0; i < j; i++)
			printf("%d", *(b + i));
		printf("\n");
		s1 = BinToHex(b);
		for (i = 0; s1[i] != '\0'; i++)
			printf("%c", s1[i]);
		printf("\n");
	}
	else if(choice==2)
	{
		c = bitShift(a);
		for (i = 0; i < j; i++)
			printf("%d", *(c + i));
		printf("\n");
		s2 = BinToHex(c);
		for (i = 0; s1[i] != '\0'; i++)
			printf("%c", s2[i]);
	}
	else if(choice==3)
	{
		d = maskOp(a);
		s3 = BinToHex(d);
		for (i = 0; s1[i] != '\0'; i++)
			printf("%c", s3[i]);
		printf("\n");
	}	
	return 0;
}