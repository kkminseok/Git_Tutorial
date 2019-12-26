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
	int max=-1;
	int resultx=0,resulty=0;
	int arr[9][9]={0,};
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			scanf("%d",&arr[i][j]);
			if(max<=arr[i][j])
			{
				resultx=i;
				resulty=j;
				max=arr[i][j];
			}
		}
	}
	printf("%d\n%d %d",max,resultx+1,resulty+1);
}
