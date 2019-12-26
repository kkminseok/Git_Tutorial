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
	int e,f,c;
	scanf("%d %d %d",&e,&f,&c);
	getchar();
	e+=f;
	int count=0;
	while(e/c!=0)
	{
		count+=e/c;
		e=(e/c)+(e%c);
	}
	
	printf("%d",count);
}
