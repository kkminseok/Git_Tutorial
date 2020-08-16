#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>

class bal
{
public:
	int sixbal = 0;
	int normalbal = 0;
};

int main()
{
	using namespace std;

	int n, m,result=0;
	int minbal1=1001, minbal2 = 1001;
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < m; ++i)
	{
		bal* arr = new bal[m];
		scanf("%d %d", &arr[i].sixbal, &arr[i].normalbal);
		getchar();
		if (arr[i].sixbal < minbal1)
			minbal1 = arr[i].sixbal;
		if (arr[i].normalbal < minbal2)
			minbal2 = arr[i].normalbal;
	}
	//6개이하
	if (n <= 6)
	{
		if (minbal1 < minbal2*n)
			result = minbal1;
		else
			result = minbal2 * n;
	}
	if (minbal1 > minbal2 * 6)
		minbal1 = minbal2 * 6;	
	if(n>6)// 6개 초과
	{
		while (n >= 6)
		{
			result += minbal1;
			n -= 6;
		}
		if (n != 0)
		{
			if (minbal1 < minbal2*n)
				result += minbal1;
			else
				result += (minbal2*n);
		}
	}
	cout << result;

}