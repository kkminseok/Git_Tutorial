#include<stdio.h>
//https://www.acmicpc.net/problem/4153
int main(int argc, char* argv[])
{
	int arr[3] = { 0, };
	char right[] = "right\n";
	char wrong[] = "wrong\n";
	while(1)
	{
		int max =0;
		int temp = 0;
		int sum = 0;
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
		{
			break;
		}
		for (int i = 0; i < 3; ++i)
		{
			
			if (max < arr[i])
			{
				max = arr[i];

				temp = i;
			}
		}
		
		for (int i = 0; i < 3; ++i)
		{
			if (i == temp)
				continue;
			else
			{
				sum += (arr[i]*arr[i]);
			}
		}
		if (sum == max * max)
			fputs(right, stdout);
		else
			fputs(wrong, stdout);
		
	}  

	return 0;
}


