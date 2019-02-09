#include<stdio.h>
#include<string.h>
void Reverse(char *s,int i,int j)
{
	if (i > j)
		return;
	char t;
	t = s[i];
	s[i] = s[j];
	s[j] = t;
	Reverse(s, i+1, j-1);
}
int main()
{
	char s[50];
	scanf("%s", s);
	Reverse(s,0,strlen(s)-1);
	printf("%s", s);
	return 0;
}