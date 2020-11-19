#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<cmath>
#include<ctime>
using namespace std;


int main()
{
	int n;
	int max=-1;
	scanf("%d",&n);
	int* arr=new int[n];
	getchar();
	for(int i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,greater<int>());
	for(int i=0;i<n;++i)
	{
		arr[i]=arr[i]+i+1;
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	printf("%d",max+1);
	
	arr=nullptr;
	delete[]arr;
	return 0;
}
