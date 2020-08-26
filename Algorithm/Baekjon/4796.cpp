#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>

int main()
{
	using namespace std;
	int l=1, p=1, v=1;
	int result = 0;
	for (int i = 0;; ++i)
	{
		result = 0;
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p==0 && v==0)
			break;
		int option = (v%p) > l ? l : v % p;
		result = v / p * l + option;
		printf("Case %d: %d\n", i + 1, result);
	}
	
}