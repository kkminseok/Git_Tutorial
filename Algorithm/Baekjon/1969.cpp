#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

int main()
{
	using namespace std;
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	int** mat = new int*[4];
	for (int i = 0; i < 4; ++i)
	{
		mat[i] = new int[m];
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mat[i][j] = 0;
		}
	}
	
	string* inputarr = new string[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> inputarr[i];
	}
	sort(inputarr, inputarr + n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (inputarr[i][j] == 'A')
			{
				mat[0][j]++;
			}
			else if (inputarr[i][j] == 'C')
			{
				mat[1][j]++;
			}
			else if (inputarr[i][j] == 'G')
			{
				mat[2][j]++;
			}
			else
				mat[3][j]++;
		}
	}
	string result = "";
	int count = 0;
	int j = 0;
	for ( j = 0; j < m; ++j)
	{
		int index = 0;
		int max =-1;
		for (int i = 0; i < 4; ++i)
		{
			if (mat[i][j] > max)
			{
				max = mat[i][j];
				index = i;
			}
		}
		if (index == 0)
		{
			result += "A";
			count += (n - mat[index][j]);
		}
		else if (index == 1)
		{
			result += "C";
			count += (n - mat[index][j]);
		}
		else if (index == 2)
		{
			result += "G";
			count += (n - mat[index][j]);
		}
		else
		{
			result += "T";
			count += (n - mat[index][j]);
		}
	}
	cout << result<<'\n'<<count;
}