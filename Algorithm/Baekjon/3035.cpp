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
	int r,c,zr,zc;
	scanf("%d %d %d %d",&r,&c,&zr,&zc);
	getchar();
	char** arr=new char*[r];
	for(int i=0;i<r;++i)
		arr[i]=new char[c];
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			scanf("%c",&arr[i][j]);
		}
		getchar();
	}
	for(int i=0;i<r*zr;++i)
	{
		for(int j=0;j<c*zc;++j)
		{
			printf("%c",arr[i/zr][j/zc]);
		}
		puts("");
	}
	
	for(int i=0;i<r;++i)
	{
		delete arr[i];
	}
	delete arr;
}
