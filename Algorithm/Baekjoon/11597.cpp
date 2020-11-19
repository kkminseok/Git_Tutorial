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
	scanf("%d",&n);
	getchar();
	int* arr=new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int i=n/2-1;
	int j=n/2;
	int temp=arr[i]+arr[j];
	while(i>0)
	{
		if(arr[i-1]+arr[j+1]<temp)				
		temp=arr[i-1]+arr[j+1];
		--i;
		++j;
		if(i==0)
		{
			printf("%d",temp);
			return 0;
		}
	}
	if(i==0)
		printf("%d",arr[0]+arr[n-1]);
	arr=nullptr;
	delete[]arr;
}
