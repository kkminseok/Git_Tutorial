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
	string password="-\\(@?>&%)";
	string input;

	while(1)
	{
		getline(cin,input);
		if(input=="#")
			break;
		int result=0;
		int count=1;
		for(int i=input.size()-1;i>=0;--i)
		{
			if(input[i]=='/')
			{
				result=(result+count*-1);
				count*=8;
			}
			else
			{
				for(int j=0;j<password.size();++j)
				{
					if(input[i]==password[j])
					{
						
						result+=(count*j);
						count*=8;
					}
				}
			}
		}
		printf("%d\n",result);
	}
	
	
}
