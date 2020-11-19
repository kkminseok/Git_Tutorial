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

void horiz(int arr[][2])
{
	int temp1=arr[1][0];
	int temp2=arr[1][1];
	
	arr[1][0]=arr[0][0];
	arr[0][0]=temp1;
	arr[1][1]=arr[0][1];
	arr[0][1]=temp2;
}
void vertic(int arr[][2])
{
	int temp1=arr[1][0];
	int temp2=arr[0][0];
	
	arr[1][0]=arr[1][1];
	arr[0][0]=arr[0][1];
	arr[1][1]=temp1;
	arr[0][1]=temp2;
}


int main()
{
	int arr[2][2]={1,2,3,4};
	string input;
	getline(cin,input);
	int hs=0;
	int vs=0;
	for(int i=0;i<input.size();++i)
	{
		if(input[i]=='H')
			++hs;
		else
			++vs;
	}
	if(hs%2==1)
		horiz(arr);
	if(vs%2==1)
		vertic(arr);
	for(int i=0;i<2;++i)
	{
		for(int j=0;j<2;++j)
		{
			printf("%d ",arr[i][j]);
		}
		puts("");
	}
}
