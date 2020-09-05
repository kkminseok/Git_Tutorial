#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

long long dp[100] = { 0,1,1 };

long long fibo(int n)
{
	if (n <= 2)
		return dp[n];
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld", fibo(n));
}