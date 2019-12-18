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
	int* arr=new int[n];
	for(int i=0;i<n;++i)
		scanf("%d",&arr[i]);
	int carlos=arr[0];
	for(int i=0;i<n;++i)
	{
		if(carlos<arr[i])
		{
			puts("N");
			arr=nullptr;
			delete[]arr;
			return 0;
		}
	}
	puts("S");
	
	arr=nullptr;
	delete[]arr;
		
}
