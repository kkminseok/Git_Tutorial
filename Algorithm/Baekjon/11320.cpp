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
		int tri1,tri2;
		scanf("%d %d",&tri1,&tri2);
		tri1*=tri1;
		tri2*=tri2;
		printf("%d\n",tri1/tri2);
	}
	
}
