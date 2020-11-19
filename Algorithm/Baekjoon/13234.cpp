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
	string one,two,op;
	cin>>one>>op>>two;
	bool bone,btwo;
	
	one =="true" ? bone=true : bone=false;
	two =="true" ? btwo=true : btwo=false;
	
	op=="AND" ? cout<<boolalpha<<(bone&&btwo) : cout<<boolalpha<<(bone||btwo);
	
	
	
	
}
