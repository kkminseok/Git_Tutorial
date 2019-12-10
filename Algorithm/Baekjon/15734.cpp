#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<cmath>
#include<ctime>
using namespace std;


int main()
{
	int l,r,a;
	int result=0;
	scanf("%d %d %d",&l,&r,&a);
	if(a==0)
	{
		l>r ? printf("%d",r*2) : printf("%d",l*2);
		return 0;
	}
	while(a>0)
	{
		if(l<r)
		{
			while(l!=r&&a>0)
			{
				++l;
				--a;
			}
			result=l*2;
		}
		else if(r<l)
		{
			while(r!=l&&a>0)
			{
				++r;
				--a;
			}
			result=r*2;
		}
		else//둘이 같을 때
		{
			if(a==1)
				--a;
			while(a>1)
			{
				++l;
				++r;
				a-=2;
			}
			result=l+r;
		}
	}
	printf("%d",result);
}
