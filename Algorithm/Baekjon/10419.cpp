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
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		int time;
		scanf("%d",&time);
		int j=0;
		while((j+1)+((j+1)*(j+1))<=time)
			++j;
		printf("%d\n",j);

	}
}
