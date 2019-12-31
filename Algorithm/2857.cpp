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
	string name[5]={"",};
	string FBI="FBI";
	bool check=false;
	for(int i=0;i<5;++i)
	{
		getline(cin,name[i]);
	}
	for(int i=0;i<5;++i)
	{
		if(name[i].find(FBI)!=string::npos)
		{
			check=true;
			printf("%d ",i+1);
		}
	}
	if(check!=true)
		puts("HE GOT AWAY!");
}
