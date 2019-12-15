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
	int n,t;
	int count=0;
	int sum=0;
	bool flag=1;
	scanf("%d %d",&n,&t);
	int* arr=new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
		if(sum+arr[i]<=t&&flag==1)
		{
			++count;
			sum+=arr[i];
		}
		else
			flag=0;
	}
	printf("%d",count);
	
	
	arr=nullptr;
	delete[]arr;
	
}
