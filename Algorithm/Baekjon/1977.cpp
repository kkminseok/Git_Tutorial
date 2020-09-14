#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>

int table[101]{ 0, };

int main()
{
	for (int i = 0; i < 101; ++i)
	{
		table[i] = pow(i + 1, 2);
	}
	int n, m;
	bool flag = false;
	scanf("%d %d", &n, &m);
	
	int result = 0;
	int start;
	for (int i = 0; i < 101; ++i)
	{
		if (table[i] == n)
		{
			start = (int)sqrt(n);
			break;
		}
		else
		{
			start = (int)sqrt(n) + 1;
		}
	}
	int min = start;
	for (; start <= (int)(sqrt(m)); ++start)
	{
		result += pow(start,2);
		flag = true;
	}
	if (!flag)
		puts("-1");
	else
		printf("%d\n%d", result, (int)pow(min, 2));
		

	
}