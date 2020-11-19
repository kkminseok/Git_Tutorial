#include<stdio.h>
#include<string.h>
#define CHARMAX 1002

int main(int argc, char* argv[])
{
	char Cae[CHARMAX] = { 0, };
	int count = 0;

	fgets(Cae, CHARMAX, stdin);
	Cae[strlen(Cae) - 1] = '\0';

	while (Cae[count] != '\0')
	{
		if (Cae[count] >= 65 && Cae[count] <= 67)
		{
			Cae[count] += 23;
		}
		else
		{
			Cae[count] -= 3;
		}
		printf("%c", Cae[count]);
		++count;
	}

	return 0;
}