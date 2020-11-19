#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

long long onedp[41] = { 0,1,1, };
long long zerodp[41] = { 1,0,1, };

long long fiboz(int n)
{
	if (n <= 2)
		return zerodp[n];
	if (zerodp[n] != 0)
		return zerodp[n];
	return zerodp[n] = fiboz(n - 1) + fiboz(n - 2);
}

long long fiboone(int n)
{
	if (n <= 2)
		return onedp[n];
	if (onedp[n] != 0)
		return onedp[n];
	return onedp[n] = fiboone(n - 1) + fiboone(n - 2);
}

int main()
{
	int t,n;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d", &n);
		
		printf("%lld %lld\n", fiboz(n), fiboone(n));
		getchar();
	}
}