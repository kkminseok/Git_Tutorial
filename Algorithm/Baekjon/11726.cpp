#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int dp[1001] = { 1,2,0, };

int getdp(int n)
{
	if (n < 3)
		return n;
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = (getdp(n - 1) + getdp(n - 2))%10007;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", getdp(n));
}