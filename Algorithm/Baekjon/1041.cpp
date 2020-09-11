#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long n;
	scanf("%lld", &n);
	int arr[6] = { 0, };
	long long result = 0;
	long long n1, n2;
	for (int i = 0; i < 6; ++i)
	{
		scanf("%d", &arr[i]);
	}
	if (n == 1)
	{
		sort(arr, arr + 6);
		result = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] ;
		printf("%lld", result);
		return 0;
	}
	arr[0] = min(arr[0], arr[5]);
	arr[1] = min(arr[1], arr[4]);
	arr[2] = min(arr[2], arr[3]);

	sort(arr, arr + 3);
	int min1 = arr[0] + arr[1] + arr[2];
	int min2 = arr[0] + arr[1];
	int min3 = arr[0];

	result += min1 * 4;
	n1 = 4 * (n - 1) + 4 * (n - 2);
	result += min2 * n1;
	n2 = (n - 1)*(n - 2)*4 + (n - 2)*(n - 2);
	result += min3 * n2;

	printf("%lld", result);

}