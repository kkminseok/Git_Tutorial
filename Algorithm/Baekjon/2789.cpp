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
	string input;
	string compare="CAMBRIDGE";
	string output="";
	getline(cin,input);
	for(int i=0;i<input.size();++i)
	{
		bool flag=false;
		int j=0;
		while(j<10)
		{	
			if(input[i]==compare[j])
			{
				flag=true;
				break;
			}
			++j;
		}
		if(flag==false)
		{
			output+=input[i];
		}		
	}
	cout<<output;	
}
