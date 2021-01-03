#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int dp[31] = { 1,0,3,0 };
	for (int i = 4; i <= n; i+=2)
	{
		//일반적인 case
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; i - j >= 0; j += 2)
		{
			dp[i] += dp[i - j] * 2;
		}
		
	}
	cout << dp[n];

	
}