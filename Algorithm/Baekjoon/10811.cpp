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
	int n,m;
	scanf("%d %d",&n,&m);
	getchar();
	vector<int> v;
	for(vector<int>::size_type i=0;i<n+1;++i)
		v.push_back(i);
	for(int i=0;i<m;++i)	
	{
		int first,end;
		scanf("%d %d",&first,&end);
		reverse(v.begin()+first,v.begin()+end+1);

	}
	for(vector<int>::size_type i=1;i<n+1;++i)
		cout<<v[i]<<" ";
	cout<<endl;
	
	
}
