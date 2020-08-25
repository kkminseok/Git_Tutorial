#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int t;
	scanf("%d", &t);
	int count[3] = { 0, };
	
	while (t > 0)
	{
		if (t - 300 >= 0)
		{
			t -= 300;
			count[0]++;
		}
		else if (t - 60 >= 0)
		{
			t -= 60;
			count[1]++;
		}
		else
		{
			t -= 10;
			count[2]++;
		}
	}
	if (t == 0)
	{
		printf("%d %d %d", count[0], count[1], count[2]);
	}
	else
		puts("-1");
	
}