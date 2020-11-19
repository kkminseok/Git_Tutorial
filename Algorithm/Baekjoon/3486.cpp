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
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		string a,b;
		int ia,ib;
		cin>>a>>b;
		cin.ignore(256,'\n');
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		ia=stoi(a);
		ib=stoi(b);
		int sum=ia+ib;
		string result=to_string(sum);
		reverse(result.begin(),result.end());
		int count=0;
		while(result[count]=='0')
		{
			++count;
		}
		for(;count<result.size();++count)
			printf("%c",result[count]);
		puts("");
				
	}
}
