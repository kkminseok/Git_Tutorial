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
	int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		int x;
		scanf("%d",&x);
		getchar();
		int result=0;
		string input,answer;
		getline(cin,input);
		getline(cin,answer);
		for(int csize=0;csize<input.size();++csize)
		{
			if(input[csize]!=answer[csize])
				++result;
		}
		
		printf("Case %d: %d\n",i+1,result);
		
		
	}
}
