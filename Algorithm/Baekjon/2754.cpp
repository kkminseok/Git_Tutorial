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
	vector<pair<string,double>> v1;
	
	v1.push_back(pair<string,double>("A+",4.3));
	v1.push_back(pair<string,double>("A0",4.0));
	v1.push_back(pair<string,double>("A-",3.7));
	
	v1.push_back(pair<string,double>("B+",3.3));
	v1.push_back(pair<string,double>("B0",3.0));
	v1.push_back(pair<string,double>("B-",2.7));
	
	v1.push_back(pair<string,double>("C+",2.3));
	v1.push_back(pair<string,double>("C0",2.0));
	v1.push_back(pair<string,double>("C-",1.7));
	
	v1.push_back(pair<string,double>("D+",1.3));
	v1.push_back(pair<string,double>("D0",1.0));
	v1.push_back(pair<string,double>("D-",0.7));
	
	v1.push_back(pair<string,double>("F",0.0));
	
	string input;
	getline(cin,input);
	for(vector<pair<string,double>>::iterator iter=v1.begin();iter!=v1.end();++iter)
	{
		if(iter->first==input)
		{
			cout<<fixed;
			cout.precision(1);
			cout<<iter->second;
				return 0;
		}
	}
	
}
