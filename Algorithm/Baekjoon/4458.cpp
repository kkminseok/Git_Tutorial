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
	string input;
	for(int i=0;i<n;++i)
	{
		getline(cin,input);
		if(input[0]>=97&&input[0]<=122)
		{
			input[0]=input[0]-32;
		}
		cout<<input<<'\n';	
	}
}
