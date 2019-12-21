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
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=1;i<=t;++i)
	{
		const int size=3;
		int tri[size]={0,0,0};
		scanf("%d %d %d",&tri[0],&tri[1],&tri[2]);
		sort(tri,tri+size);
		if((tri[0]*tri[0])+(tri[1]*tri[1])==(tri[2]*tri[2]))
			printf("Scenario #%d:\nyes\n",i);
		else
			printf("Scenario #%d:\nno\n",i);
		
		puts("");
		
	}
	
}
