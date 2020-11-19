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
	while(1)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==0&&b==0)
			break;
		printf("%d\n",a-(b-a));	
	}
}
