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
	int age,weight;
	string name;
	do
	{
		cin>>name>>age>>weight;
		if(name[0]=='#'&&age==0&&weight==0)
			break;
		if(age>17||weight>=80)
			cout<<name<<" Senior\n";
		else
			cout<<name<<" Junior\n";
	}while(1);
}
