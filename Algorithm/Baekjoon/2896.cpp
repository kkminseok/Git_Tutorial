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

//사실상 int비교이므로 오차위험이 없을거라 생각
int findmin(double ora,double ap,double pine)
{
	if(ora<=ap&&ora<=pine)
		return 0;
	else if(ap<ora&&ap<pine)
		return 1;
	else 
		return 2;
}


int main()
{
	double ora,ap,pine;
	double orp,app,pinep;
	double arr[3];
	scanf("%lf %lf %lf",&ora,&ap,&pine);
	getchar();
	scanf("%lf %lf %lf",&orp,&app,&pinep);
	arr[0]=orp;
	arr[1]=app;
	arr[2]=pinep;
	while(orp<=ora&&app<=ap&&pinep<=pine)
	{
		ora-=orp;
		ap-=app;
		pine-=pinep;
	}
	
	//최저값 찾기
	if(ora!=0&&ap!=0&&pine!=0)
	{
		int min=findmin(ora,ap,pine);
		
		printf("%.4lf %.4lf %.4lf",ora-(orp/arr[min]),ap-(app/arr[min]),pine-(pinep/arr[min]));
	}
	else
		printf("%.0lf %.0lf %.0lf",ora,ap,pine);
	
}
