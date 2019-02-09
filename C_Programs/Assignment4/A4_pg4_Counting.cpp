#include<stdio.h>
int main()
{
	char *s[] = { "we will teach you how to","Move a mountain", "level of building","Erase the past","Make a million" };
	int i, j,c=0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; s[i][j] != '\0'; j++)
		{
			if (s[i][j] == 'e')
				c++;
		}
	}
	printf("Number of e = %d", c);
	return 0;
}