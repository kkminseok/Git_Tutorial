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

int checked(char p1,char p2)
{
	if(p1=='R')
	{
		if(p2=='R')
			return 0;
		else if(p2=='P')
			return -1;
		else 
			return 1;
	}
	else if(p1=='P')
	{
		if(p2=='R')
			return 1;
		else if(p2=='P')
			return 0;
		else
			return -1;
	}
	else
	{
		if(p2=='R')
			return -1;
		else if(p2=='P')
			return 1;
		else
			return 0;
	}
	
}

int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		int n;
		scanf("%d",&n);
		getchar();
		
		char p1,p2;// 바위, 보, 가위
		int player1=0;
		for(int j=0;j<n;++j)
		{
			scanf("%c %c",&p1,&p2);
			getchar();
			player1+=checked(p1,p2);
		}
		if(player1>0)
			puts("Player 1");
		else if(player1<0)
			puts("Player 2");
		else
			puts("TIE");
		
		
	}
}
