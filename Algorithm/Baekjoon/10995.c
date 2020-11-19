#include<stdio.h>

//https://www.acmicpc.net/problem/10995
int main()
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < N; ++j)
				fputs("* ", stdout);
		}
		else
		{
			for (int j = 0; j < N; ++j)
				fputs(" *", stdout);
		}
		puts("");
	}

	return 0;
}


