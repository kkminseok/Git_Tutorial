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
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;++i)
	{
		string name;
		getline(cin,name);
		int good=0;
		int bad=0;
		for(int j=0;j<name.size();++j)
		{
			if(name[j]=='g'||name[j]=='G')
				++good;
			else if(name[j]=='b'||name[j]=='B')
				++bad;
			
		}
		if(good>bad)
			cout<<name<<" is GOOD\n";
		else if(good<bad)
			cout<<name<<" is A BADDY\n";
		else
			cout<<name<<" is NEUTRAL\n";
	}
}
