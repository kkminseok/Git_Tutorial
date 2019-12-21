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
using namespace std;




int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		
		const int size=5;
		int arr[size]={0,};
		for(int j=0;j<size;++j)
		{
			scanf("%d",&arr[j]);
		}
		sort(arr,arr+size);
		if(arr[3]-arr[1]>3)
			puts("KIN");
		else
		{
			printf("%d\n",arr[1]+arr[2]+arr[3]);
		}
		
	}
	
	
}
