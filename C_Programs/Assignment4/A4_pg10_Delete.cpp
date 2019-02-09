#include<stdio.h>
#include<string.h>
int main()
{
	char s[50];
	char c;
	int i, j;
	//printf("%s", s);
	printf("enter the character\n");
	scanf("%c",&c);
	printf("enter name\n");
	scanf("%s", s);
	//c = 'i';
	for (i = 0, j = 0; s[i] != '\0'; i++)
	{
		if (s[i] != c)
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
	printf("%s", s);
	return 0;
}