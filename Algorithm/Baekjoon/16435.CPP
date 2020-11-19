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
	int n,l;
	scanf("%d %d",&n,&l);
	int* arr=new int[n];
	for(int i=0;i<n;++i)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	
	for(int i=0;i<n;++i)
	{
		if(arr[i]<=l)
			++l;
		else
		{
			printf("%d",l);
			arr=nullptr;
			delete[]arr;
			return 0;
		}
	}
	printf("%d",l);
	
	arr=nullptr;
	delete[]arr;
}
