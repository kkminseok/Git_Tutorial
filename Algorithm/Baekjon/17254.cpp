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

class Keyboard
{
	public:
	int boardnum;
	int second;
	char input;
	
	void setboard(int boar){this->boardnum=boar;}
	void setsecond(int _second){this->second=_second;}
	void setin(char _in){this->input=_in;}
	
	bool operator<(const Keyboard& a)
	{
		if(this->second==a.second)
		{
			return this->boardnum<a.boardnum;
		}
		return this->second<a.second;
	}
	
	
};

int main()
{
	int n,m;
	int _board,_second;
	char _input;
	scanf("%d %d",&n,&m);
	getchar();
	Keyboard* arr=new Keyboard[m];
	for(int i=0;i<m;++i)
	{
		scanf("%d %d %c",&_board,&_second,&_input);
		arr[i].setboard(_board);
		arr[i].setsecond(_second);
		arr[i].setin(_input);
	}
	sort(arr,arr+m);
	for(int i=0;i<m;++i)
		printf("%c",arr[i].input);
	arr=nullptr;
	delete[]arr;
	
	
	
	
}
