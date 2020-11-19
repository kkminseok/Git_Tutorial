#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;
bool isPrime(int n)
{
	
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int bpoint = 0;
	//소수 표

	while (1)
	{
		bool collect = false;
		scanf("%d", &bpoint);
		if (bpoint == 0)
			return 0;
		int a = 3;
		int b = bpoint - a;
		while (a <= b)
		{
			if (isPrime(a) && isPrime(b))
			{
				printf("%d = %d + %d\n", bpoint, a, b);
				collect = true;
				break;
			}
			a += 2;
			b -= 2;
		}

		if (collect == false)
		{
			puts("Goldbach's conjecture is wrong.");
		}
		bpoint += 2;
		
	}
	return 0;

}
