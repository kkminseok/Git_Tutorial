#include<stdio.h>
#include<string.h>
#include<math.h>
//https://www.acmicpc.net/problem/11816
#define CHARNUM 100

int main()
{
	char X[CHARNUM];
	int sum = 0;
	int expo = 0;

	fgets(X, CHARNUM, stdin);
	int length = strlen(X) - 2;

	if (X[0] == '0')//8진수
	{
		if (X[1] == 'x')// 16진수
		{
			while (length > 1)
			{
				if (X[length] >= 97 && X[length] <= 102)
				{
					sum += ((int)X[length] - 87)*(int)pow(16 , expo);
				}
				else
				{
					sum += ((int)X[length] - 48)*(int)pow(16 , expo);
				}
				++expo;
				--length;
			}
		}
		else//8진수
		{
			while (length > 0)
			{
				sum += ((int)X[length] - 48)*(int)pow(8, expo);
				++expo;
				--length;
			}

		}
	}
	else// 10진수
	{
		sum = atoi(X);
	}
	printf("%d", sum);


	return 0;
}