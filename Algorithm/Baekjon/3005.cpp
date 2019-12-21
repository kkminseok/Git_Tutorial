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
	
	int r,c;
	scanf("%d %d",&r,&c);
	getchar();
	string* result=new string[r*c];
	int resultcount=0;
	
	char** arr;
	arr=new char*[r+1];
	for(int i=0;i<r;++i)
		arr[i]=new char[c+1];
	
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			scanf("%c",&arr[i][j]);
		}
		getchar();
	}
	//가로
	for(int i=0;i<r;++i)
	{
		int count=0;
		string temp;
		int j=0;
		while(j<c)
		{
			if(arr[i][j]=='#')
			{
				if(count>=2)
				{
					result[resultcount]=temp;
					++resultcount;
					temp="";
					count=0;
					++j;
				}
				else
				{
					temp="";
					count=0;
					++j;
				}
			}
			else
			{
				temp+=arr[i][j];
				++count;
				++j;
			}
			
		}
		if(j==c&&count>=2)
		{
			result[resultcount]=temp;
			++resultcount;
		}
		

	}
	//세로
	
	for(int j=0;j<c;++j)
	{
		int count=0;
		string temp;
		int i=0;
		while(i<r)
		{
			if(arr[i][j]=='#')
			{
				if(count>=2)
				{
					result[resultcount]=temp;
					++resultcount;
					temp="";
					count=0;
					++i;
				}
				else
				{
					temp="";
					count=0;
					++i;
				}
			}
			else
			{
				temp+=arr[i][j];
				++count;
				++i;
			}
			
		}
		if(i==r&&count>=2)
		{
			result[resultcount]=temp;
			++resultcount;
		}
	}
	sort(result,result+resultcount);
	cout<<result[0];
	
}
