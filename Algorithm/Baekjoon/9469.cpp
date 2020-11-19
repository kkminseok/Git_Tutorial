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
	getchar();
	for(int i=0;i<n;++i)
	{
		int t;
		double d,a,b,f;
		scanf("%d %lf %lf %lf %lf",&t,&d,&a,&b,&f);
		double result=(d/(a+b)*f);
		printf("%d %lf\n",t,result);
		
		
	}
}
