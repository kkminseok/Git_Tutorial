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

void swap(int arr[],int& x,int& y)
{
	int temp=x;
	x=y;
	y=temp;
	
}
void print(int arr[])
{
	for(int i=0;i<5;++i)
		printf("%d ",arr[i]);
	puts("");
}

bool checkarr(int arr[])
{
	for(int i=0;i<5;++i)
	{
		if(arr[i]!=i+1)
			return false;
	}
	return true;
}

int main()
{
	int arr[5]={0,};
	scanf("%d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]);
	while(!checkarr(arr))
	{
		if(arr[0]>arr[1])
		{
			swap(arr,arr[0],arr[1]);
			print(arr);
		}
		if(arr[1]>arr[2])
		{
			swap(arr,arr[1],arr[2]);
			print(arr);
		}
		if(arr[2]>arr[3])
		{
			swap(arr,arr[2],arr[3]);
			print(arr);
		}
		if(arr[3]>arr[4])
		{
			swap(arr,arr[3],arr[4]);
			print(arr);
		}
	}	
}
