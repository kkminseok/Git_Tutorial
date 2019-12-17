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
	int i,sum=0;
	int science[4]={0,};
	int soical[2]={0,};
	for(i=0;i<4;++i)
	{
		scanf("%d",&science[i]);
	}
	for(i=0;i<2;++i)
	{
		scanf("%d",&soical[i]);
	}
	sort(science,science+4,greater<int>());
	sort(soical,soical+2,greater<int>());
	sum=science[0]+science[1]+science[2]+soical[0];
	printf("%d",sum);
	
}
