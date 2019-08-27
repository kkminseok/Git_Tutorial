#include<stdio.h>
#include<math.h>
//https://www.acmicpc.net/problem/9020

#define NUM 10000


int main()
{
	static int prime[NUM + 1];
	int i, j, Limit;
	
	for (i = 2; i <= NUM; ++i)
		prime[i] = 1;
	
	Limit = (int)sqrt(NUM);
	for (i = 2; i <= Limit; ++i)
	{
		if (prime[i] == 1)
		{
			for (j = 2 * i; j <= NUM; ++j)
			{
				if (j%i == 0)
					prime[j] = 0;
			}
		}
	}

	int T, input;
	int result1=0, result2=0;
	scanf("%d", &T);
	
	getchar();
	for (int i = 0; i < T; ++i)
	{
		int dif = 9999;
		scanf("%d", &input);
		getchar();
		for (int j = 2; j <= NUM&&j<=input; ++j)
		{
			if (prime[j] != 1)
				continue;
			else
			{

				if (prime[input-j] == 1)
				{
					if (abs((input - j) - j) < dif)
					{
						dif = input - j - j;
						result1 = j;
						result2 = input - j;
						
					}
					
					
				}
			}
			
		}
		printf("%d %d\n", result1, result2);


	}

	return 0;
}


