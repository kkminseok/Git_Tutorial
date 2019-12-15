#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<cmath>
#include<ctime>
#include<vector>
using namespace std;


int main()
{
	int n;
	int i;
	scanf("%d",&n);
	getchar();
	long long* arr=new long long[n];
	for(int k=0;k<n;++k)
		scanf("%lld",&arr[k]);
	sort(arr,arr+n);
	for(i=0;i<n;++i)
	{
		if(arr[i]!=(i+1))
		{
			printf("%d",i+1);
			arr=nullptr;
			delete[]arr;
			return 0;
		}
	}
	printf("%d",i+1);
	arr=nullptr;
	delete[]arr;
	return 0;
	
}
