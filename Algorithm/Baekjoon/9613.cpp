#include<cstdio>

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	for (int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d", &n);
		int* arr = new int[n];
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &arr[j]);
		}
		getchar();
		long long sum = 0;
		for (int j = 0; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				sum += gcd(arr[j], arr[k]);
			}
		}
		printf("%lld\n", sum);

		delete[] arr;
	}
}
