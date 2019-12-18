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
	if(arr[1]-arr[0]==arr[2]-arr[1])//등차수열
		printf("%d",arr[n-1]+(arr[1]-arr[0]));
	else//등비수열
		printf("%d",arr[n-1]*(arr[1]/arr[0]));
		
		
	arr=nullptr;
	delete[]arr;
}
