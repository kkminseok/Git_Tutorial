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
		string input;
		getline(cin,input);
		cout<<i+1<<". "<<input<<'\n';
	}
}
