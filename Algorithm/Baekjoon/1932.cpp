#include<iostream>
#include<algorithm>

using namespace std;

int result = 0;
int dp[501][501] = { 0, };
int tri[501][501] = { 0, };
void Solution()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
			cin >> tri[i][j];
	}
	dp[1][1] = tri[1][1];
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j == 1)
			{
				dp[i][1] = dp[i - 1][j] + tri[i][j];
			}
			else if (j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j] + tri[i][j], dp[i - 1][j - 1] + tri[i][j]);
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (max < dp[n][i])
			max = dp[n][i];
	}
	cout << max << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solution();
}