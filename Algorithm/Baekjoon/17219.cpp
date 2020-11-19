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

class Memo
{
	public:
	string site;
	string pass;
	
	bool operator<(const Memo& a)
	{
		return site<a.site;
	}
	
};

int bsearch(Memo arr[],string target,int size)
{
	int low=0;
	int high=size-1;
	int mid;
	
	while(low<=high)
	{
		mid=(low+high)/2;
		
		if(arr[mid].site==target)
			return mid;
		else if(arr[mid].site>target)
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,m;
	string temp;
	cin>>n>>m;
	cin.ignore(256,'\n');
	
	Memo* arr=new Memo[n];
	
	for(int i=0;i<n;++i)
	{
		cin>>arr[i].site>>arr[i].pass;
	}
	sort(arr,arr+n);
	for(int i=0;i<m;++i)
	{
		cin>>temp;
		cout<<arr[bsearch(arr,temp,n)].pass<<'\n';
		
	}
	
	arr=nullptr;
	delete[]arr;
	
}
