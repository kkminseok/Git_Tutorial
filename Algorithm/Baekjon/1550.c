#include<stdio.h>
#include<math.h>
#include<string.h>

#define CHARNUM 8
int main()
{
	char A[CHARNUM] = { 0, };
	int count;
	int sum = 0;
	int expo = 0;

	fgets(A, CHARNUM, stdin);
	
	count = strlen(A)-2;
	
	
	while (count > -1)
	{
	
		if (A[count] >= 65 && A[count] <= 70)
		{
			sum += ((int)A[count] -55)* (int)pow(16, expo);
			
		}
		else
		{
			sum += ((int)A[count] - 48)*(int)pow(16, expo);
		}
		++expo;
		
		--count;
	}
	printf("%d", sum);

	return 0;
}