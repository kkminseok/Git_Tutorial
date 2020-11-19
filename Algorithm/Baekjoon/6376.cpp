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
	puts("n e");
	puts("- -----------");
	double e=1;
	double sum=1;
	puts("0 1 \n1 2 \n2 2.5 \n3 2.666666667\n4 2.708333333");
	for(int n=1;n<10;++n)
	{
		sum=1;
		for(double j=n;j>0;--j)
		{
			sum*=j;
		}
		e+=(1/sum);
		if(n>=5)
		printf("%d %.9lf\n",n,e);
	}
	
	
	
	
}
