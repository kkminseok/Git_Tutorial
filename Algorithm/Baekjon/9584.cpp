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
	int count=0;
	bool flag=0;
	getline(cin,input);
	int n;
	scanf("%d",&n);
	getchar();
	string* result=new string[n];
	for(int i=0;i<n;++i)
	{
		string temp;
		getline(cin,temp);
		for(int j=0;j<input.size();++j)
		{
			if(input[j]==temp[j]||input[j]=='*')
				flag=1;
			else 
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			result[count]=temp;
			++count;
		}
		
	}
	printf("%d\n",count);
	for(int i=0;i<count;++i)
		cout<<result[i]<<'\n';
	
	result=nullptr;
	delete[]result;
}
