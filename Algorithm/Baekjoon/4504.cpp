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
	int n;
	scanf("%d",&n);
	getchar();
	int input;
	while(1)
	{
		scanf("%d",&input);
		if(input==0)
			return 0;
		if(input%n!=0)
		{
			printf("%d is NOT a multiple of %d.\n",input,n);
		}
		else
		{
			printf("%d is a multiple of %d.\n",input,n);
		}
	}
	
}
