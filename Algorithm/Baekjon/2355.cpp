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


void swap(int& a,int& b)
{
	int temp=a;
	a=b;
	b=temp;
}

int main()
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
	if(a>b)
		swap(a,b);
	printf("%lld",((b-a+1)*(a+b))/2);
	//n*(a+l)/2 시그마 공식
}
