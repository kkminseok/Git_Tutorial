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
	int t=0;
	int r,e,c;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		scanf("%d %d %d",&r,&e,&c);
		if(r+c<e)
			puts("advertise");
		else if(r+c==e)
			puts("does not matter");
		else
			puts("do not advertise");	
	}	
}
