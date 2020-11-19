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




int main()
{
	int size;
	bool arr[4]={false,};// 0은 숫자 1 은 소문자 2는 대문자 3은 특수문자
	string pass;
	int plusch=0;
	
	scanf("%d",&size);
	getchar();
	getline(cin,pass);
	//일단 한바퀴를 돈다.
	for(int i=0;i<pass.size();++i)
	{
		//숫자
		if(pass[i]>=48&&pass[i]<=57)
			arr[0]=true;
		//알파벳 소문자
		else if(pass[i]>=97&&pass[i]<=122)
			arr[1]=true;
		//알파벳 대문자
		else if(pass[i]>=65&&pass[i]<=90)
			arr[2]=true;
		//특수문자
		else
			arr[3]=true;		
		
	}
	for(int i=0;i<4;++i)
	{
		if(arr[i]!=true)
			++plusch;
	}
	if(plusch+pass.size()>=6)
		printf("%d",plusch);
	else
		printf("%d",(6-(int)(pass.size())));
		
}
