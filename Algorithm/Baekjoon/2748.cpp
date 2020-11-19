#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

long long data[100];
long long fibo(int n)
{
	if (n <= 2)
		return 1;
	if (data[n] != 0)
	{
		return data[n];
	}
	else
	{
		data[n] = fibo(n - 1) + fibo(n - 2);
		return data[n];
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld", fibo(n));
}