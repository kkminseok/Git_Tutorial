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
	int n,count=1;
	int second=0;
	scanf("%d",&n);
	while(n!=0)
	{
		n-=count;
		++count;
		++second;
		if(count>n)
		{
			count=1;
		}
	}
	printf("%d",second);
}
