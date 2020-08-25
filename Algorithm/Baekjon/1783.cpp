#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>

int main()
{
	using namespace std;
	int n, m,result=1;
	scanf("%d %d", &n, &m);
	//4가지 방법을 못 쓸 때
	if (n < 3 || m < 7)
	{
		if (n == 2)
		{
			result = m / 2 + m%2;
			if (result > 4)
				result = 4;
		}
		else if (n>2)// 그냥 m임 그러나 4넘으면 4로수정
		{
			result = m;
			if (result > 4)
				result = 4;
		}
	}
	else
		result = m - 2;
	printf("%d", result);
}