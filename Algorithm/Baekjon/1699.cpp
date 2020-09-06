#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
int dp[100001] = { 1, };
int main()
{
	int n;
	scanf("%d", &n);
	int result = 0;
	for (int i = 0; i <= n; ++i)
		dp[i] = i;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 2; j*j <= i; ++j)
			dp[i]=std::min(dp[i], dp[i - j * j] + 1);
	}

	printf("%d", dp[n]);

	return 0;
}