#include<iostream>

const int mok = 1000000000;
const int MAX = 201;

using namespace std;

int dp[MAX][MAX] = { 0, };
int n, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i <= k; ++i)
		dp[0][i] = 1;
	for (int i = 0; i <= n; ++i)
		dp[i][1] = 1;
	for (int i = 0; i <= n; ++i)
		dp[i][2] = i + 1;


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 3; j <= k; ++j)
		{
			for (int r = 0; r <= i; ++r)
			{
				dp[i][j] += dp[r][j-1];
				dp[i][j] %= mok;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
			cout << dp[i][j] << " ";
		cout << '\n';
	}
	
	cout << dp[n][k];


}