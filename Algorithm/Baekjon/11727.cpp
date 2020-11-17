#include<iostream>
using namespace std;

void Solution()
{
	int n;
	cin >> n;
	int dp[1001] = { 0, };
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < n + 1; ++i)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2])%10007;
		
	}

	cout << dp[n];
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}