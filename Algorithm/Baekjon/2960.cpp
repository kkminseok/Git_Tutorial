#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>

int main()
{
	int n, k;
	int arr[1001] = { 0, };
	bool check[1001] = { false };
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; ++i)
	{
		arr[i] = i;
	}
	int count = 0;
	int a = 2;
	while (1)
	{
		int temp = a;
		for (; a <= n; a += temp)
		{
			if (!check[a])
			{
				check[a] = true;
				++count;
				if (count == k)
				{
					printf("%d", arr[a]);
					return 0;
				}
			}
		}
		a = temp + 1;
	}
	



}