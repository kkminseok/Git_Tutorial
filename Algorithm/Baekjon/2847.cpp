#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>

int main()
{
	using namespace std;
	int n;
	int count = 0;
	scanf("%d", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	
	for (int j = n - 1; j > 0; --j)
	{
		if (arr[j] <= arr[j - 1])
		{
			count += (arr[j - 1] - arr[j] + 1);
			arr[j - 1]-= (arr[j - 1] - arr[j] + 1);
		}
	}
	cout << count;
}