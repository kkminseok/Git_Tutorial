#include<iostream>

using namespace std;

int dp[1001][10] = { 0, };
int n;
int result = 1;
void Input()
{
	cin >> n;
	for (int i = 0; i < 10; ++i)
		dp[1][i] =1;
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 1;

}

void Solve()
{
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
			if (i == n)
			{
				result += dp[i][j];
				result %= 10007;
			}

		}
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
	if (n == 1)
		cout << 10;
	else
		cout << result;
}