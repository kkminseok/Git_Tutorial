#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int n,b,c;
	scanf("%d", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &b, &c);

	long long result = 0;
	for (int i = 0; i < n; ++i)
	{
		++result;
		if (arr[i] - b < 0)
			continue;
		else
		{
			result += ((arr[i] - b) / c);
			if ((arr[i] - b) % c > 0)
				++result;
		}
	}
	printf("%lld", result);
}