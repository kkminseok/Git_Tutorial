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
	int n,sum=0;
	scanf("%d",&n);
	getchar();
	int* B=new int[n];
	int* A=new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&B[i]);
	}
	for(int i=0;i<n;++i)
	{
		A[i]=(B[i]*(i+1))-sum;
		sum+=A[i];
		printf("%d ",A[i]);
	}
	A=nullptr;
	delete[]A;
	B=nullptr;
	delete[]B;

}
