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
	int k;
	double h,p;
	while(~scanf("%lf %lf",&h,&p))
	{
		getchar();
		printf("%.2lf\n",h/p);
		
	}
}
