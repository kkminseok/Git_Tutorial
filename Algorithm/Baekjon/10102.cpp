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
	


int main()
{
	int vote;
	int a=0,b=0;
	scanf("%d",&vote);
	getchar();
	string input;
	getline(cin,input);
	for(int i=0;i<input.size();++i)
	{
		if(input[i]=='A')
			++a;
		else
			++b;
	}
	a == b ? puts("Tie") : (a > b ? puts("A") : puts("B"));

	
}
