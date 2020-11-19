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

bool operator==(string& a,string& b)
{
	return a==b;
}

int main()
{
	
	string input;
	string motion=":-";
	
	getline(cin,input);
	int i=0,j=0;
	int happycount=0;
	int sadcount=0;
	while(i<input.size())
	{
		while(input[i]==motion[j]&&i<input.size())
		{
			++i;
			++j;
			if(j==2)
			{
				if(input[i]==')')
					++happycount;
				else if(input[i]=='(')
					++sadcount;
			}
			
		}
		j=0;
		++i;
	}
	if(happycount==0&&sadcount==0)
		puts("none");
	else if(happycount==sadcount)
		puts("unsure");
	else if(happycount>sadcount)
		puts("happy");
	else
		puts("sad");

}
