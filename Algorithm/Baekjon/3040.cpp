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
	int arr[9]={0,};
	int sum=0;
	for(int i=0;i<9;++i)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	
	for(int i=0;i<8;++i)
	{
		for(int j=i+1;j<9;++j)
		{
			int temp=arr[i]+arr[j];
			if((sum-temp)==100)
			{
				arr[i]=0;
				arr[j]=0;
				sort(arr,arr+9);
				for(int i=2;i<9;++i)
				{
					printf("%d\n",arr[i]);
				}
				return 0;
			}
		}
	}
}
