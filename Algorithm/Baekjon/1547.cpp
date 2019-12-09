#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<cmath>
#include<ctime>
using namespace std;

void swap(int arr[],int a,int b)
{
	--a;
	--b;
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

int main()
{
	int n;
	int result;
	int arr[3]={1,0,0};
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		swap(arr,x,y);
	}
	for(int i=0;i<3;++i)
	{
		if(arr[i]==1)
			result=i;
	}
	
	printf("%d",result+1);
	
	return 0;
}
