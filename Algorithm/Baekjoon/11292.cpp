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
class Student
{
	public:
	double height;
	string name;
	int height2;
	void change(double height)
	{
		height2=(int)(height*100);
	}
	
	bool operator<(const Student& a)
	{
		return this->height2>a.height2;
	}
};

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			return 0;
		Student* arr=new Student[n];
		for(int i=0;i<n;++i)
		{
			cin>>arr[i].name>>arr[i].height;
			arr[i].change(arr[i].height);
		}
		sort(arr,arr+n);
		int i=0;
		cout<<arr[i].name<<" ";
		while(arr[i].height2==arr[i+1].height2)
		{
			++i;
			cout<<arr[i].name<<" ";
		}
		puts("");
		
		arr=nullptr;
		delete[]arr;
		
	}
	
	
	
}
