#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;

int main()
{
	double result = 0;
	int n;
	scanf("%d", &n);
	double maxnum = 0;
	double temp = 0;
	for (int i = 0; i < n; ++i)
	{
		double num;
		scanf("%lf", &num);
		if (i == 0)
		{
			maxnum = num;
			temp = num;
			continue;
		}
		if (temp * num > num)
		{
			temp *= num;
		}
		else
		{
			temp = num;
		}
		if (maxnum < temp)
			maxnum = temp;
	}
	printf("%.3lf", maxnum);
}