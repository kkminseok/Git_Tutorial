#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>

int main()
{
	using namespace std;
	int n,temp=0;
	scanf("%d", &n);
	getchar();
	int* arr = new int[n];
	int sum = 0;
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	sum = 1;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (sum < arr[i])
		{
			result = sum;
			break;
		}
		else
			sum += arr[i];
	}
	if (i == n)
		result = sum;
	cout << result;
}