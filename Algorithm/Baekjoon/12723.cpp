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
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		int size;
		int sum=0;
		scanf("%d",&size);
		getchar();
		int* arr1=new int[size];
		int* arr2=new int[size];
		for(int j=0;j<size;++j)
			scanf("%d",&arr1[j]);
		for(int j=0;j<size;++j)
			scanf("%d",&arr2[j]);
		sort(arr1,arr1+size);
		sort(arr2,arr2+size,greater<int>());
		
		for(int j=0;j<size;++j)
		{
			//printf("%d %d\n",arr1[j],arr2[j]);
			sum+=(arr1[j]*arr2[j]);
		}
		
		printf("Case #%d: %d\n",i+1,sum);
		
	}
	
}
