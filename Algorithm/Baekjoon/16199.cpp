#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<cmath>
#include<ctime>
using namespace std;


int main()
{
	int firsty,firstm,firstd;
	int secondy,secondm,secondd;
	scanf("%d %d %d",&firsty,&firstm,&firstd);
	getchar();
	scanf("%d %d %d",&secondy,&secondm,&secondd);
	getchar();
	int global=0;
	int korea=secondy-firsty+1;
	int law=secondy-firsty;
	//global
	if(firsty==secondy)//년이 같다.
		global=0;
	else if(secondm>firstm)//월이 더 큼
	{
		global=secondy-firsty;
	}
	else if(secondm<firstm)// 월이 적을 때 년은 다름
	{
		global=secondy-firsty-1;
	}
	else if(secondm==firstm&&secondd>=firstd)//월은 같지만 날짜가 더 클 때
		global=secondy-firsty;
	else if(secondm==firstm&&secondd<firstd)//월은 같지만 날자까 더 작음
		global=secondy-firsty-1;
	
	printf("%d\n",global);
	printf("%d\n",korea);
	printf("%d\n",law);
	
}
