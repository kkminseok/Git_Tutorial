#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int n;
	int result = 0;
	scanf("%d", &n);
	int* arr = new int[n];
	int temp;
	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &temp);
		if (temp == n)
		{
			++result;
		}
	}
	printf("%d", result);
	

	return 0;
}