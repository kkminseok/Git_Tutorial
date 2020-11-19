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
	
	int n,k;
	scanf("%d",&n);
	string* arr=new string[n];
	getchar();
	for(int i=0;i<n;++i)
	{
		getline(cin,arr[i]);
	}
	scanf("%d",&k);
	if(k==1)
	{
		for(int i=0;i<n;++i)
		{
			cout<<arr[i]<<'\n';
		}
	}
	else if(k==3)
	{
		for(int i=n-1;i>=0;--i)
			cout<<arr[i]<<'\n';
	}
	else
	{
		for(int i=0;i<n;++i)
		{
			for(int j=n-1;j>=0;--j)
				cout<<arr[i][j];
			puts("");
		}
	}
	
	
	
	arr=nullptr;
	delete[]arr;
	
}
