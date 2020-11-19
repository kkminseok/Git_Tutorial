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
int t;
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;++i)
	{
		int problem;
		scanf("%d",&problem);
		getchar();
		int* arr=new int[problem*2];
		bool* checked=new bool[problem*2];
		int* result=new int[problem];
		int count=0;
		for(int j=0;j<problem*2;++j)
		{
			scanf("%d",&arr[j]);
			checked[j]=false;
		}
		for(int j=0;j<problem*2;++j)
		{
			for(int k=0;k<=j;++k)
			{
				if(((arr[j]/4)*3)==arr[k]&&checked[k]==false)
				{
					checked[k]=true;
					checked[j]=true;
					result[count]=arr[k];
					++count;
					break;
				}
			}
		}
		printf("Case #%d:",i+1);
		for(int j=0;j<problem;++j)
		{
			printf(" %d",result[j]);
		}
		puts("");
		
		
		arr=nullptr;
		delete[]arr;
		checked=nullptr;
		delete[]checked;
		result=nullptr;
		delete[]result;
		
	}
	
}
