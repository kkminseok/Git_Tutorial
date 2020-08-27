#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>

int main()
{
	int n, m;
	int result = 0;
	scanf("%d %d", &n, &m);
	int** arr = new int*[n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
		
	getchar();
	int r, c, d;
	scanf("%d %d %d", &r, &c, &d);
	getchar();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				arr[i][j]++;
		}
		
	}
	while (1)
	{
		int tempcount = 0;
		if (arr[r][c] == 0 ||arr[r][c]==1)
		{
			if (arr[r][c] != 1)
			{
				arr[r][c] = 1;
				++result;
			}
			while (tempcount != 4)
			{
				if (d == 0)
				{
					if (arr[r][c - 1] == 0 && c - 1 > 0)
					{
						d = 3;
						c--;
						break;
					}
					else
					{
						d = 3;
						++tempcount;
					}
				}
				else if (d == 3)
				{
					if (arr[r + 1][c] == 0 && r + 1 < n)
					{
						d = 2;
						r++;
						break;
					}
					else
					{
						d = 2;
						++tempcount;
					}
				}
				else if (d == 2)
				{
					if (arr[r][c + 1] == 0 && c + 1 < m)
					{
						d = 1;
						++c;
						break;
					}
					else
					{
						d = 1;
						++tempcount;
					}
				}
				else if (d == 1)
				{
					if (arr[r - 1][c] == 0 && r - 1 > 0)
					{
						d = 0;
						--r;
						break;
					}
					else
					{
						d = 0;
						++tempcount;
					}
				}
			}
			if (tempcount == 4)
			{
				if (d == 0)
				{
					if (arr[r + 1][c] == 2)
						break;
					else
						++r;
				}
				else if (d == 1)
				{
					if (arr[r][c - 1] == 2)
						break;
					else
						--c;
				}
				else if (d == 2)
				{
					if (arr[r - 1][c] == 2)
						break;
					else
						--r;
				}
				else if (d == 3)
				{
					if (arr[r][c + 1] == 2)
						break;
					else
						++c;
				}
			}
		}
	}
	printf("%d", result);

	
}