#include<stdio.h>
#define MAX 100
#define Book(name,author) #name "is written by" #author
#define Print(s) printf("token"#s" = %d ",token##9);
int main()
{
	int token9 = 100;
	printf("%s\n", Book(ANSI, Swamy));
	Print(9);
	#ifdef MAX
		#undef MAX
		#define MAX 99;
	#else
		printf("%d", MAX);
	#endif
	return 0;
}