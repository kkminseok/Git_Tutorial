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
	int r,c;
	scanf("%d %d",&r,&c);
	getchar();
	char** arr=new char*[2*r];
	for(int i=0;i<2*r;++i)
		arr[i]=new char[2*c];
	
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			arr[i][j]=fgetc(stdin);
		}
		getchar();
	}
	//오른쪽 대칭
	for(int i=0;i<r;++i)
	{
		int temp=c-1;
		for(int j=c;j<2*c;++j)
		{
			arr[i][j]=arr[i][temp--];
		}
	}
	//밑으로 대칭
	int temp=r-1;
	for(int i=r;i<2*r;++i)
	{

		for(int j=0;j<2*c;++j)
		{
			arr[i][j]=arr[temp][j];
		}
		--temp;
	}
	int a,b;
	scanf("%d %d",&a,&b);
	a--;
	b--;
	
	for(int i=0;i<2*r;++i)
	{
		for(int j=0;j<2*c;++j)
		{
			if(i==a&&j==b)
			{
				if(arr[i][j]=='#')
					fputc('.',stdout);
				else
					fputc('#',stdout);
				continue;
			}
			printf("%c",arr[i][j]);
		}
		puts("");
	}
	
}
