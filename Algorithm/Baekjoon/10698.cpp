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
	int first,second,result;
	int finall;
	char op;
	for(int i=0;i<t;++i)
	{
		scanf("%d %c %d = %d",&first,&op,&second,&result);
		getchar();	
		op=='+' ? finall=first+second : finall=first-second;
		
		//cout<<result<<" "<<finall<<'\n';
		
		finall==result ? printf("Case %d: YES\n",i+1) : printf("Case %d: NO\n",i+1);
		
	}

}
