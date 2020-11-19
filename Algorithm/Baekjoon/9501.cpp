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
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		int n,d,count=0;
		scanf("%d %d",&n,&d);
		getchar();
		
		for(int j=0;j<n;++j)
		{
			double speed,fuel,percent;
			scanf("%lf %lf %lf",&speed,&fuel,&percent);
			getchar();
			double fp=fuel/percent;
			double result=fp*speed;
			if(result>=(double)d)
				++count;
		}
		printf("%d\n",count);
	}
}
