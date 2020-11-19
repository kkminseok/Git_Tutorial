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
	int n;
	int count2=0;
	vector<int> arr1;
	vector<int> arr2;
	while(scanf("%d",&n)!=EOF)
	{
		arr1.push_back(n);
		arr2.push_back(n);
		++count2;
	}
	sort(arr2.begin(),arr2.end());
	for(vector<int>::size_type i=0;i<arr1.size();++i)
	{
		if(arr1[i]!=arr2[i])
		{
			puts("Bad");
			return 0;
		}
	}
	puts("Good");
	
}
