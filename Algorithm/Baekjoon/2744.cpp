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
	string input;
	getline(cin,input);
	for(int i=0;i<input.size();++i)
	{
		if(input[i]>=97&&input[i]<=122)//소문자일 때
		{
			input[i]=input[i]-32; //대문자
		}
		else//대문자만 들어오는게 보장
		{
			input[i]=input[i]+32;
		}
	}
	cout<<input;
	
}
