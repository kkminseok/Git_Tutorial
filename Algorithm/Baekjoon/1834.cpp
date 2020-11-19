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
	
	long long sum=0;
	long long count=1;
	while(count!=n)
	{
		sum+=((n*count)+count);
		++count;
	}
	printf("%lld",sum);
}
