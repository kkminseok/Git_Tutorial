#include<iostream>
#include<algorithm>
using namespace std;


void Solution()
{
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int** dp = new int* [2];
		int** arr = new int* [2];
		int n;
		cin >> n;
		
		for (int j = 0; j < 2; ++j)
		{
			dp[j] = new int [n+1];
			arr[j] = new int[n+1];
		}
		for (int k = 0; k < 2; ++k)
		{
			for (int j = 1; j <= n; ++j)
			{
				cin >> arr[k][j];
			}
		}
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];


		for (int j = 2; j <=n ; ++j)
		{
			dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + arr[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + arr[1][j];
		}
		dp[0][n] < dp[1][n] ? cout << dp[1][n]<<'\n' : cout << dp[0][n]<<'\n';


		for (int j = 0; j < 2; ++j)
		{
			delete[] arr[j];
			delete[] dp[j];
		}
		delete[] arr;
		delete[] dp;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}