#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char **s,name[50],*t;
	int n,i,len,j;
	printf("enter no of rows\n");
	scanf("%d", &n);
	s = (char **)malloc(sizeof(char*)*n);
	for (i = 0; i < n; i++)
	{
		printf("enter name\n");
		scanf("%s", name);
		len = strlen(name);
		s[i] = (char*)malloc(sizeof(char)*len);
		strcpy(s[i], name);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(s[i], s[j]) == 1)
			{
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%s\n", s[i]);
	for (i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}c 