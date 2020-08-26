#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		for (int count = 0; count < i; ++count)
		{
			fputs(" ",stdout);
		}
		for (int j = 0; j < 2*(n - i)-1; ++j)
			fputs("*", stdout);
		puts("");
	}
}