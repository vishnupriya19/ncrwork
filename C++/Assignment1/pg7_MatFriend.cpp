#include<stdio.h>
#include<iostream>
using namespace std;
class Matrix
{
	int **p;
	int m, n;
	public:
	Matrix()
	{
		int i, j;
		cout << "Enter number of rows and columns\n";
		cin >> m >> n;
		p = new int*[m];
		for (i = 0; i < m; i++)
			p[i] = new int[n];
		printf("Enter elements\n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				scanf("%d", &p[i][j]);
		}
	}
	friend void matrixMul(Matrix, int);
};
void matrixMul(Matrix mat, int s)
{
	int i, j;
	for (i = 0; i < mat.m; i++)
	{
		for (j = 0; j < mat.n; j++)
			cout << mat.p[i][j] *s << " ";
		cout << "\n";
	}
}
int main()
{
	Matrix mat;
	int s;
	printf("enter scalar to multiply\n");
	scanf("%d", &s);
	matrixMul(mat, s);
	return 0;
}