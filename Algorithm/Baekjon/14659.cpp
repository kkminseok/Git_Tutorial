#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	int n,count=0,max=0,j=0;
	scanf("%d", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; ++i)
	{
		count = 0;
		j = i + 1;
		while(arr[i]>arr[j]&& j<n)
		{ 
			++count;
			++j;
		}
		if (count > max)
			max = count;
	}
	printf("%d", max);
}