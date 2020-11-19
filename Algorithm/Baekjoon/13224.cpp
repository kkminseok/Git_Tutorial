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

void swap(int arr[],int a,int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
int main()
{
	string temp;
	int arr[3]={1,0,0};
	getline(cin,temp);
	for(string::size_type i=0;i<temp.size();++i)
	{
		if(temp[i]=='A')
			swap(arr,0,1);
		else if(temp[i]=='B')
			swap(arr,1,2);
		else
			swap(arr,0,2);
	}
	for(int i=0;i<3;++i)
	{
		if(arr[i]==1)
			printf("%d",i+1);
	}
	
}
