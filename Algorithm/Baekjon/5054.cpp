#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<cmath>
#include<ctime>
#include<vector>
#include<ctype.h>
#include<utility>
using namespace std;



int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		int n;
		scanf("%d",&n);
		getchar();
		int* arr=new int[n];
		for(int j=0;j<n;++j)
		{
			scanf("%d",&arr[j]);
		}
		sort(arr,arr+n);
		printf("%d\n",((arr[n-1]-arr[0])*2));
		
	}
}
