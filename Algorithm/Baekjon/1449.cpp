#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
int main()
{
	using namespace std;
	int N, L,result=0;
	scanf("%d %d", &N, &L);
	getchar();
	bool arr[1001] = { 0 };
	int temp;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &temp);
		arr[temp] = true;
	}
	L -= 1;//¸ÕÀú »©ÁØ´Ù. 
	for (int i = 0; i < 1001; ++i)
	{
		if (arr[i] == true)
		{
			int count = 0;
			++result;
			while (i < 1001 && count < L)
			{
				++count;
				++i;
			}
		}
	}
	cout << result;


}