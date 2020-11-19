#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<cmath>
#include<ctime>
using namespace std;


int main()
{
	string book;
	string newbook="";
	string keyword;
	getline(cin,book);
	getline(cin,keyword);
	
	for(int i=0;i<book.size();++i)
	{
		while(book[i]>47&&book[i]<58)//숫자
			++i;
		newbook+=book[i];
	}
	if(newbook.find(keyword)<101)
		puts("1");
	else
		puts("0");

	
}
