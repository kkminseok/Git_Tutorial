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
	bool flag=false;
	int ulrim[9]={0,};
	int nis[9]={0,};
	int ulrimcount=0;
	int niscount=0;
	for(int i=0;i<9;++i)
	{
		scanf("%d",&ulrim[i]);
	}
	for(int i=0;i<9;++i)
	{
		scanf("%d",&nis[i]);
	}
	for(int i=0;i<9;++i)
	{
		//일단 ulrim먼저 더하고 시작 초
		ulrimcount+=ulrim[i];
		//말
		if(ulrimcount>niscount) 
			flag=true;
		niscount+=nis[i];
		
		
	}
	flag == true ? puts("Yes"):puts("No");
	
	
}
