#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int k = 1;
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		if (i < n)
		{
			for (int j = 0; j < n - i - 1; ++j)
			{
				fputs(" ", stdout);
			}
			for (int j = 0; j < i + 1; ++j)
			{
				fputs("*", stdout);
			}
			puts("");
		}
		else
		{
			for (int j = 0; j < i - n + 1; ++j)
			{
				fputs(" ", stdout);
			}
			for (int j =0; j < n-k; ++j)
			{
				fputs("*", stdout);
			}
			++k;
			puts("");
		}
	}
}