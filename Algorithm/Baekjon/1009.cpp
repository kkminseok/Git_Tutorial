#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int temp = a;
		if (a > 10)
			a %= 10;
		if (a %10==0)
		{
			puts("10");
		}
		else
		{
			for (int j = 0; j < b-1; ++j)
			{
				a = a * temp;
				if (a > 10)
				{
					a %= 10;
				}
			}
			printf("%d\n", a);
		}
		
	}
}