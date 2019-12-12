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
	for(int i=0;i<n;++i)
	{
		printf("%d ",arr[i]);
	}
	
	arr=nullptr;
	delete[]arr;

}
