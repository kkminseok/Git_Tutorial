#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
int main()
{
	using namespace std;

	int n, m, k;
	int sum = 0;
	int result=0;
	scanf("%d %d %d", &n, &m, &k);
	sum = n + m;
	while (sum > k)
	{
		if (n < 2 || m < 1 || n+m-k<3)
			break;
		result++;
		n -= 2;
		m -= 1;
		sum = n + m;
	}
	cout << result;
}


