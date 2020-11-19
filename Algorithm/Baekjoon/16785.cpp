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
	scanf("%d %d %d",&a,&b,&c);
	int i=0;
	int sum=0;
	while(sum<c)
	{
		sum+=a;
		++i;
		if((i%7)==0)
			sum+=b;
	}
	printf("%d",i);
		
}
