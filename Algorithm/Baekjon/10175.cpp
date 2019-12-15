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
	cin.tie(NULL);
	int n;
	string comp="CBWM";
	int value[4]={1,2,3,4};
	
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;++i)
	{
		int result[4]={0,0,0,0};
		bool flag=1;
		int max=-1;
		int index=-1;
		string location;
		string speices;
		cin>>location>>speices;
		for(int size=0;size<speices.size();++size)
		{
			for(int k=0;k<comp.size();++k)
			{
				if(comp[k]==speices[size])
					result[k]+=value[k];
			}
		}
		//cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3]<<'\n';
		for(int size=0;size<4;++size)
		{
			if(result[size]>max)
			{
				max=result[size];
				index=size;
			}
			else if(result[size]==max)
				flag=0;
		}
		if(flag!=0)
		{
		switch(index)
			{
				case 0:
					cout<<location<<": "<<"The Coyote is the dominant species\n";
					break;
				case 1:
					cout<<location<<": "<<"The Bobcat is the dominant species\n";
					break;
				case 2:
					cout<<location<<": "<<"The Wolf is the dominant species\n";
					break;
				case 3:
					cout<<location<<": "<<"The Mountain Lion is the dominant species\n";
					break;
			}
		}
		else
			cout<<location<<": "<<"There is no dominant species\n";
	}
	
}
