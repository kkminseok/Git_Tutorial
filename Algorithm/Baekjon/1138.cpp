#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>

int main()
{
	using namespace std;
	int n,index=0;
	scanf("%d", &n);
	int* arr = new int[n];
	int* result = new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		result[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		index = arr[i];
		for (int j = 0; j < index; ++j)
		{
			if (result[j] != 0 && result[j] < i + 1)
				++index;
		}
		while (result[index] != 0)
		{
			++index;
		}

		result[index] = i + 1;
	}
	for (int i = 0; i < n; ++i)
		cout << result[i] << " ";

	delete arr;

	return 0;
}