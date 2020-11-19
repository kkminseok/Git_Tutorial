#include<string>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<cmath>
#include<ctime>
using namespace std;

class count2
{
	public:
	char alpha;
	int countal=0;
	
	bool operator<(const count2& a)
	{
		if(this->countal==a.countal)	
			return this->alpha<a.alpha;
		else 
			return this->countal>a.countal;
	}
};

int main()
{
	char a;
	count2 countch[26];
	while((a=getchar())!=EOF)
	{
		if(a>=97&&a<=122)
		{
		countch[a-97].alpha=a;
		countch[a-97].countal++;
		}
	}
	sort(countch,countch+26);
	int i=0;
	printf("%c",countch[0].alpha);
	while(countch[i].countal==countch[i+1].countal&&i<25)
	{
		printf("%c",countch[i+1].alpha);
		++i;
	}
	
	
	return 0;
}
