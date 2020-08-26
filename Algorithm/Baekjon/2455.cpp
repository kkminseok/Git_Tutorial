#define _CRT_SECURE_NO_WARNINGS	
#include<cstdio>

int main()
{
	int n, m;
	int result = 0;
	int temp = 0;
	for (int i = 0; i < 4; ++i)
	{
		scanf("%d %d", &n, &m);
		result += m - n;
		if (temp < result)
			temp = result;
	}
	printf("%d", temp);
	
}