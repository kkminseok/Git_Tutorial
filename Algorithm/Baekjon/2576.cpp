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
	bool check=false;
	int arr[7]={0,};
	vector<int> odd;
	for(int i=0;i<7;++i)
	{
		scanf("%d",&arr[i]);
		if(arr[i]%2==1)
		{
			check=true;
			odd.push_back(arr[i]);
		}
	}
	if(check==false)
	{
		puts("-1");
	}
	else
	{
		sort(odd.begin(),odd.end());
		int sum=0;
		for(vector<int>::size_type i=0;i!=odd.size();++i)
		{
			sum+=odd[i];
		}
		printf("%d\n%d",sum,odd[0]);
		
	}
	
}
