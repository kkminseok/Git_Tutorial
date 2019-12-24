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
	bool check[31]={false};
	int n=0;
	for(int i=0;i<28;++i)
	{
		scanf("%d",&n);
		check[n]=true;
	}
	for(int i=1;i<31;++i)
	{
		if(check[i]!=true)
			printf("%d\n",i);
	}
	
}
