#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long divide5(long long num)
{
	long long append = 0;
	for (long long i = 5; i <= num; i *= 5)
	{
		append += num / i;
	}
	return append;
}
long long divide2(long long num)
{
	long long append = 0;
	for (long long i = 2; i <= num; i *= 2)
	{
		append += num / i;
	}
	return append;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, m;
	cin >> n >> m;
	
	cout << min(divide5(n) - (divide5(n - m) + divide5(m)), divide2(n) - (divide2(n - m) + divide2(m)));
	

	return 0;
}