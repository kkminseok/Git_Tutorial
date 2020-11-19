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

class People
{
	public:
	int index=0;
	int score=0;
	bool operator<(const People& a)
	{
		return this->score<a.score;
	}
};

int main()
{
	People arr[8];
	int temp;
	int indexarr[5]={0,};
	for(int i=0;i<8;++i)
	{
		
		scanf("%d",&temp);
		arr[i].index=i+1;
		arr[i].score=temp;
	}
	sort(arr,arr+8);
	int sum=0;
	for(int i=7;i>2;--i)
		sum+=arr[i].score;
	printf("%d\n",sum);
	for(int i=0;i<5;++i)
		indexarr[i]=arr[i+3].index;
	sort(indexarr,indexarr+5);
	for(int i=0;i<5;++i)
		printf("%d ",indexarr[i]);
}
