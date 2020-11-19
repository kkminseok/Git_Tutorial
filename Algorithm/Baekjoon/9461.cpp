#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	unsigned long long arr[101] = { 1,1,1,2,2,3,4,5,0 };
	for (int i = 6; i < 101; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	for (int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", arr[n-1]);
	}
}