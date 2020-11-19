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

class Shake
{
	public:
	int Problem;
	int penalty;
	
	bool operator<(const Shake& a)
	{
		if(this->Problem!=a.Problem)
		{
			return this->Problem>a.Problem;
		}
		return this->penalty<a.penalty;
		
	}
};


int main()
{
	int n;
	int count=0;
	scanf("%d",&n);
	getchar();
	Shake* arr=new Shake[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&arr[i].Problem,&arr[i].penalty);
	}
	sort(arr,arr+n);
	
	

	for(int i=4;i<n;++i)
	{
		while(arr[4].Problem==arr[i+1].Problem)
		{
			++count;
			++i;
		}
	}
	printf("%d\n",count);
	
	arr=nullptr;
	delete[]arr;
	
}
