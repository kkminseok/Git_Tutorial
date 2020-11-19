#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<ctime>
int main()
{
	int n;
	scanf("%d", &n);
	int cnt = 2;
	int result = 0;
	int i = 1;
	time_t start, end;

	start = time(NULL);
	while (n != 1)
	{
		while (n%cnt == 0)
		{
			n /= cnt;
			++result;
			printf("%d\n", cnt);
		}
		++cnt;
	}
	end = time(NULL);
	//double resulttime = (double)end - start;


	
}