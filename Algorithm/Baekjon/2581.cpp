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
	int m,n;
	bool flag=false;
	int result=0;
	int sum=0;
	scanf("%d %d",&m,&n);
	getchar();
	int arr[10001]={0,};
	for(int i=2;i<10001;++i)
		arr[i]=i;
	for(int i=2;i<10001;++i)
	{
		if(arr[i]==0)continue;
		for(int j=i+i;j<10001;j+=i)
			arr[j]=0;
	}
	for(int i=m;i<=n;++i)
	{
		if(arr[i]!=0)
		{
			if(flag==false)
			{
				result=i;
				flag=true;
			}
			sum+=arr[i];
		}
		
	}
	if(result==0)
		puts("-1");
	else
	printf("%d\n%d",sum,result);
}
