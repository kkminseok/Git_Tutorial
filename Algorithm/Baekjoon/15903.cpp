#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>


int main()
{
	using namespace std;

	int n, m;
	long long result = 0;
	scanf("%d %d", &n, &m);
	long long* arr = new long long[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	for (int i = 0; i < m; i++) {
		sort(arr, arr + n);
		long long tmp = arr[1] + arr[0];
		arr[0] = tmp; arr[1] = tmp;
	}
	for (int i = 0; i < n; ++i)
	{
		result += (long long)arr[i];
	}
	cout << result;

	delete arr;
}