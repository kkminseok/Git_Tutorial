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
	
bool checktri(int x,int y,int z)//값만 필요
{
	if(x==y)
		return 1;
	else if(x==z)
		return 1;
	else if(y==z)
		return 1;
	else
		return 0;
}

int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	if(x+y+z!=180)
		puts("Error");
	else if(x==60&&y==60&&z==60)
	{
		puts("Equilateral");
	}
	else if(checktri(x,y,z))
	{
		puts("Isosceles");
	}
	else
		puts("Scalene");
}
