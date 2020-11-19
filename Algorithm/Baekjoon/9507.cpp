#include<iostream>
using namespace std;

const int MAX = 69;

long long dp[MAX] = { 0, };

void Solution()
{
	int t;
	cin >> t;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < MAX; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}

	for (int i = 0; i < t; ++i)
	{
		int input;
		cin >> input;
		cout << dp[input] << '\n';
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}