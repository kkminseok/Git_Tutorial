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
	int ko,en,ma;
	string name;
	
	bool operator<(const Student& a)
	{
		if(this->ko!=a.ko)//1.조건 국어 점수가 감소하는 순서
		{
			return this->ko>a.ko;
		}
		else if(this->en==a.en&&this->ma==a.ma) //점수가 다 같다.
		{
			return this->name<a.name;
		}
		else if(this->en==a.en) //국어,영어만 같다.
		{
			return this->ma>a.ma;
		}
		else
		{
			return this->en<a.en;
		}
		
	}
};

int main()
{
	
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	Student* arr=new Student[n];
	for(int i=0;i<n;++i)
	{
		string temp;
		cin>>arr[i].name>>arr[i].ko>>arr[i].en>>arr[i].ma;
		//cout<<arr[i].name<<arr[i].ko<<arr[i].en<<arr[i].ma;
	}
	sort(arr,arr+n);
	for(int i=0;i<n;++i)
	{
		cout<<arr[i].name<<'\n';
	}
	arr=nullptr;
	delete[]arr;
	
	
}
