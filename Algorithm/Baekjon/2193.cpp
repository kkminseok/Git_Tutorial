#include<iostream>
using namespace std;

long long dp[91] = { 0, };

void Solution()
{
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < 91; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
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