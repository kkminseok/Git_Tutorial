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
using namespace std;



int main()
{
	string input="";
	while(1)
	{
		bool alpha[26]={false,};
		getline(cin,input);
		if(input[0]=='*')
			break;
		for(int i =0;i<input.size();++i)
		{
			if(input[i]==' ')
				continue;
			else
				alpha[input[i]-97]=true;
		}
		int i;
		for(i=0;i<26;++i)
		{
			if(alpha[i]==false)
			{
				puts("N");
				break;
			}
		}
		if(i==26)
			puts("Y");
		
		
		
	}
	
}
