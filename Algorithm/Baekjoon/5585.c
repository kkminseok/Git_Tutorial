#include<stdio.h>

int main()
{
	int money[6] = { 500,100,50,10,5,1 };
	int N,count=0;
	int result = 0;
	
	scanf("%d", &N);
	int exchange = 1000 - N;
	while (exchange > 0)
	{
		if (exchange - money[count] >= 0)
		{
			exchange -= money[count];
				++result;
		}
		else
		{
			++count;
		}
	}
	printf("%d", result);

	return 0;
}


