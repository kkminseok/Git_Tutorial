#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
int main()
{
	int n;
	scanf("%d", &n);
	int result = 0;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	std::sort(arr, arr + n);
	result = arr[0] * arr[n - 1];
	printf("%d", result);

}