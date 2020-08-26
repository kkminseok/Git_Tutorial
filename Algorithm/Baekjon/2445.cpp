#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			fputs("*",stdout);
		}
		for (int j = 2*(n - i - 1) ; j > 0; j--)
		{
			fputs(" ", stdout);
		}
		for (int j = 0; j < i + 1; ++j)
		{
			fputs("*", stdout);
		}
		puts("");
	}
	for (int i = 0; i < n*2; ++i)
		fputs("*", stdout);
	puts("");
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n-i-1 ; ++j)
		{
			fputs("*", stdout);
		}
		for (int j =0;j<2*(i+1);++j)
		{
			fputs(" ", stdout);
		}
		for (int j = 0; j < n-i-1; ++j)
		{
			fputs("*", stdout);
		}
		puts("");
	}
}