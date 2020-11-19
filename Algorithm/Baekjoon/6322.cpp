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
	double a,b,c;
	int count=1;
	while(1)
	{
		scanf("%lf %lf %lf",&a,&b,&c);//세변
		if(a==0&&b==0&&c==0)
			break;
		getchar();
		if(c==-1)// 빗변을 모를 때
		{
			c=sqrt(a*a+b*b);	
			printf("Triangle #%d\nc = %.3lf\n\n",count,c);
		}
		else if(a==-1)
		{
			if(b>c||b==c)
			{
				printf("Triangle #%d\n",count);
				puts("Impossible.\n");
			}
			else
			{
				a=sqrt(c*c-b*b);
				printf("Triangle #%d\na = %.3lf\n\n",count,a);
			}
		}
		else
		{
			if(a>c||a==c)
			{
				printf("Triangle #%d\n",count);
				puts("Impossible.\n");
			}
			else
			{
				b=sqrt(c*c-a*a);
				printf("Triangle #%d\nb = %.3lf\n\n",count,b);
			}
		}
			
		count++;
		
	}
	
	
}
