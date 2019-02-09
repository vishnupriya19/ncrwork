#include<stdio.h>
#include<string.h>
int replace(char *s)
{
	int i, c = 0;
	for (i = 0; s[i]!='\0' ; i++)
	{
		if (s[i] == ' ')
		{
			s[i] = '-';
			c++;
		}
	}
	return c;
}
int main()
{
	int n;
	char *cat = "The cat sat";
	//printf("%s", cat);
	//printf("Hello");
	n = replace(cat);
	//printf("Hello");
	printf("%s",cat);
	return 0;
}