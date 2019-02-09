#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int replace(char *s)
{
	int i,c=0;
	for (i = 0; s[i] != '\0'; i++)
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
	char *s;
	int n;
	s = (char*)malloc(sizeof(char) * 15);
	strcpy(s, "the cat sat");
	n = replace(s);
	printf("%d\n", n);
	printf("%s", s);
	free(s);
}