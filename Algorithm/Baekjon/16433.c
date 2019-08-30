#include<stdio.h>
#include<stdlib.h>



int main()
{
	int N, R, C;
	
	scanf("%d %d %d", &N, &R, &C);
	
	//2단동적할당.
	char** arr = (char**)calloc(sizeof(char*), N);
	for (int i = 0; i < N; ++i)
		arr[i] = (char*)calloc(sizeof(char), N);

	R -= 1;
	C -= 1;
	if (R % 2 != 0 && C % 2 == 0||R%2==0&&C%2==1)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i % 2 == 0 && j % 2 == 0)
					arr[i][j] = '.';
				else if (i % 2 == 1 && j % 2 == 1)
					arr[i][j] = '.';
				else
					arr[i][j] = 'v';
			}
		}
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i % 2 == 0 && j % 2 == 1)
					arr[i][j] = '.';
				else if (i % 2 == 1 && j % 2 == 0)
					arr[i][j] = '.';
				else
					arr[i][j] = 'v';
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%c", arr[i][j]);
		}
		puts("");
	}
	

	//2단 동적할당 해제
	for (int i = 0; i < N; ++i)
		free(arr[i]);
	free(arr);
	return 0;
}