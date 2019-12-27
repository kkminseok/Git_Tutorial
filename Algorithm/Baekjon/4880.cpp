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
#include<utility>
using namespace std;

int main()
{
	int a,b,c;
	while(1)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a==0&&b==0&&c==0)
		{
			return 0;
		}
		if(c-b==b-a)
		{
			printf("AP %d\n",2*c-b);
		}
		else
		{
			printf("GP %d\n",c*(c/b));
		}
		
	}
	
	
}
