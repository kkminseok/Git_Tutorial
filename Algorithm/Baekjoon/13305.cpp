#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

class road
{
public:
	long long dis=0;
	long long price;
};

int main()
{
	using namespace std;

	int n;
	int idx = 0;
	long long result = 0;
	scanf("%d", &n);

	road* total = new road[n];
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%d", &total[i].dis);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &total[i].price);
	}
	int i = 0;
	result = total[0].price * total[0].dis;
	long long min = total[0].price;
	for (i = 1;i < n;++i)
	{
		if (total[i].price < min)
			min = total[i].price;
		result += (min * total[i].dis);
	}
	printf("%ld", result);


}