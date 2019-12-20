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
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		int n,m;
		int count=0;
		scanf("%d %d",&n,&m);
		for(int j=1;j<n;++j)
		{
			for(int k=j+1;k<n;++k)
			{
				if((((j*j)+(k*k)+m)%(j*k))==0)
					++count;
			}
		}
		printf("%d\n",count);
	}
}
