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
	double* arr=new double[n];
	for(int i=0;i<n;++i)
		scanf("%lf",&arr[i]);
	sort(arr,arr+n);
	printf("%.2lf",arr[1]);
	
	arr=nullptr;
	delete[]arr;
}
