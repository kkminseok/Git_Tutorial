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
using namespace std;



int main()
{
	char op='a';
	int sum=0;
	scanf("%d",&sum);
	getchar();
	scanf("%c",&op);
	getchar();
	int input=0;
	while(1)
	{
		scanf("%d",&input);
		getchar();
		switch(op)
		{
			case '+':
				sum+=input;
				break;
			case '-':
				sum-=input;
				break;
			case '*':
				sum*=input;
				break;
			case '/':
				sum/=input;
				break;
		}
		
		scanf("%c",&op);
		if(op == '=')
			break;

		
	}
	printf("%d",sum);
}
