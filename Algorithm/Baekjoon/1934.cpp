#include<cstdio>
/*
	최소공배수 문제
*/
int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	for (int i = 0; i < T; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", lcm(a, b));
	}
}
