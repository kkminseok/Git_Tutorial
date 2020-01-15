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
	string input;
	getline(cin,input);
	int sum=1;
	for(int i=0;i<input.size();++i)
	{
		if(input[i]=='c')
		{
			sum*=26;
			while(input[i]==input[i+1]&&i+1<input.size())
			{
				sum*=25;
				++i;
			}
		}
		else
		{
			sum*=10;
			while(input[i]==input[i+1]&&i+1<input.size())
			{
				sum*=9;
				++i;
			}
		}
	}
	printf("%d",sum);
}
