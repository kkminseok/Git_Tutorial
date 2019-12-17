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
	int arr[300000]={0,};
	for(int i=2;i<300000;++i)
		arr[i]=i;
	for(int i=2;i<300000;++i)
	{
		if(arr[i]==0)continue;
		for(int j=i+i;j<300000;j+=i)
			arr[j]=0;
	}
	while(1)
	{
		int input;
		scanf("%d",&input);
		if(input==0)
			return 0;

		int count=0;
		for(int i=input+1;i<=(input*2);++i)
		{
			if(arr[i]!=0)
			{
				++count;
			}

		}
		printf("%d\n",count);
	}
	
	
}
