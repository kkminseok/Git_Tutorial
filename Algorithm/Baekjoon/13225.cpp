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
		int temp;
		int count=1;
		scanf("%d",&temp);
		getchar();
		for(int j=1;j<=(temp/2);++j)
		{
			
			if((temp%j)==0)
			{
				++count;
			}
		}
		printf("%d %d\n",temp,count);
	}
	
	
	
	
}
