#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<algorithm>
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n;
		int idx = 0;
		scanf("%d", &n);
		int* arr = new int[n];
		int* result = new int[n];
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &arr[j]);
		}
		std::sort(arr, arr + n);
		for (int j = 0; j < n; ++j)
		{
			if (j % 2 == 0)//Â¦¼ö
			{
				result[idx] = arr[j];
				++idx;
			}
			else
			{
				result[n - idx] = arr[j];
			}
		}
		int max = 0;
		for (int j = 0; j < n-1; ++j)
		{
			if (abs(result[j + 1] - result[j]) > max)
				max = abs(result[j + 1] - result[j]);
		}
		printf("%d\n", max);
		delete arr;
		delete result;
	}
}