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
	string input;
	string compare="aeiou";
	int count=0;
	getline(cin,input);
	for(int i=0;i<input.size();++i)
	{
		for(int j=0;j<compare.size();++j)
		{
			if(input[i]==compare[j])
				++count;
		}
	}
	printf("%d",count);
}
