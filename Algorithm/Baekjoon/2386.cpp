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
	char input;
	int count;
	while(1)
	{
		scanf("%c",&input);
		if(input=='#')
			return 0;
		getchar();
		string line;
		count=0;
		getline(cin,line);
		transform(line.begin(),line.end(),line.begin(),::tolower);
		for(int i=0;i<line.size();++i)
			if(input==line[i])
			{
				++count;
			}
		printf("%c %d\n",input,count);
	}
	
	
}
