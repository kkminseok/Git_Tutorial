#include<iostream>

using namespace std;

int dp[1001][1001] = { 0, };

int nCr(int n, int k)
{
	if (n == k)
		return 1;
	if (k == 0)
		return 1;
	else if (dp[n][k] != 0)
		return dp[n][k];
	return dp[n][k] = (nCr(n - 1, k - 1) + nCr(n - 1, k)) % 10007;
	
}

void Solve(int n, int k)
{
	int result =nCr(n, k);
	cout << result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	Solve(n, k);

	return 0;
}