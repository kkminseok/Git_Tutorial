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

class User
{
	public:
	string name;
	int count=0;
	
	bool operator<(const User& a)
	{
		return this->count>a.count;
	}
};


int main()
{
	int n;
	int sangc=0;
	int changc=0;
	int jinc=0;
	string problem;
	scanf("%d",&n);
	getchar();
	
	getline(cin,problem);
	int k=2;
	for(int i=0;i<n;++i)
	{
		int check=i%3;
		if(problem[i]==(check)+65)
		{
			++sangc;
		}
		if(i%4==0&&problem[i]=='B')
		{
			++changc;
		}
		else if(problem[i]==((i-1)%4+65))
		{
			++changc;
		}
		if(problem[i]==(k%3+65))
		{
			++jinc;
		}
		if(i%2==1)
			++k;
			
	}
	
	User arr[3];
	arr[0].name="Adrian";
	arr[0].count=sangc;
	arr[1].name="Bruno";
	arr[1].count=changc;
	arr[2].name="Goran";
	arr[2].count=jinc;
	sort(arr,arr+3);
	
	int index=0;
	printf("%d\n",arr[0].count);
	cout<<arr[index].name<<'\n';
	while(arr[index].count==arr[index+1].count&&index<2)
	{
		cout<<arr[index+1].name<<'\n';
		++index;
	}
	
	
}
