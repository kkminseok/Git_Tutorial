#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	using namespace std;
	int result = 0;
	int min = 2001;
	int temp = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (i < 3)
		{
			scanf("%d", &temp);
			if (min > temp)
			{
				min = temp;
			}
			if (i == 2)
			{
				result += min;
				min = 2001;
			}
		}
		else
		{
			scanf("%d", &temp);
			if (min > temp)
			{
				min = temp;
			}
		}
	}
	result += min;
	result -= 50;
	printf("%d", result);
}