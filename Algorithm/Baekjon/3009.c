#include<stdio.h>

int main(int argc, char* argv[])
{
	int xarr[4], yarr[4];
	
	for (int i = 0; i < 3; ++i)
	{
		scanf("%d %d", &xarr[i], &yarr[i]);
		getchar();
	}
	if (xarr[0] != xarr[1] && xarr[0] != xarr[2])
	{
		printf("%d ", xarr[0]);
	}
	else if(xarr[1]!=xarr[2]&&xarr[1]!=xarr[0])
	{
		printf("%d ", xarr[1]);
	}
	else
	{
		printf("%d ", xarr[2]);
	}

	if (yarr[0] != yarr[1] && yarr[0] != yarr[2])
	{
		printf("%d", yarr[0]);
	}
	else if (yarr[1] != yarr[2] && yarr[1] != yarr[0])
	{
		printf("%d", yarr[1]);
	}
	else
	{
		printf("%d", yarr[2]);
	}


	return 0;
}


