#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

void matreverse(int** arr, int i, int j)
{
	int row = i + 3;
	int col = j + 3;
	for (int k = i; k < row; ++k)
	{
		for (int z = j; z < col; ++z)
		{
			arr[k][z] = (arr[k][z] == 1 ? 0 : 1);
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int** mat, ** result;
	mat = new int*[n];
	result = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		mat[i] = new int[m];
		result[i] = new int[m];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", &mat[i][j]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", &result[i][j]);
		}
	}
	if (n < 3 && m < 3)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (mat[i][j] != result[i][j])
				{
					puts("-1");
					return 0;
				}

			}
			if (i == n - 1)
			{
				puts("0");
				return 0;
			}
		}

	}
	int count = 0;
	for (int i = 0; i <= n - 3; ++i)
	{
		for (int j = 0; j <= m - 3; ++j)
		{
			if (mat[i][j] != result[i][j])
			{
				matreverse(mat, i, j);
				++count;
			}
			/*
			if (j == m - 3)
			{

				for (int k = j; k < m; ++k)
				{
					if (mat[i][k] != result[i][k])
					{
						puts("-1");
						return 0;
					}
				}
			}
			*/
		}
	}
	/*
	for (int k = n - 2; k < n; ++k)
	{
		for (int r = 0; r < m; ++r)
		{
			if (mat[k][r] != result[k][r])
			{
				puts("-1");
				return 0;
			}
		}
	}
	*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mat[i][j] != result[i][j])
			{
				puts("-1");
				return 0;
			}
		}
	}
	printf("%d", count);

}