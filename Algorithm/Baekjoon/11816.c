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

	if (X[0] == '0')//8����
	{
		if (X[1] == 'x')// 16����
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
		else//8����
		{
			while (length > 0)
			{
				sum += ((int)X[length] - 48)*(int)pow(8, expo);
				++expo;
				--length;
			}

		}
	}
	else// 10����
	{
		sum = atoi(X);
	}
	printf("%d", sum);


	return 0;
}