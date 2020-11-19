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
	int n;
	int max=0;
	int start=0;
	int end=0;
	
	scanf("%d",&n);
	getchar();
	int* arr=new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n-1;++i)
	{
		if(arr[i]<arr[i+1])//오르막길
		{
			start=i;
			while(arr[i]<arr[i+1]&&i<n-1)
			{
				
				end=i+1;
				++i;
			}
			if(max<arr[end]-arr[start])
			{
				max=arr[end]-arr[start];
			}
		}
	}
	printf("%d\n",max);
	arr=nullptr;
	delete[]arr;
}
