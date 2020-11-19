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
	int m,f;
	while(1)
	{
		scanf("%d %d",&m,&f);
		if(m==0&&f==0)
			break;
		getchar();
		printf("%d\n",m+f);
	
	}
}
