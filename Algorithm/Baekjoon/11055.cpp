#include<iostream>
#include<cmath>

using namespace std;

int arr[1001] = { 0, };
int dp[1001] = { 0, };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int result = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		dp[i] = arr[i];
		for (int j = 1; j < i; ++j)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
			{
				dp[i] = dp[j] + arr[i];
			}
		}

		result = max(dp[i], result);
	}
	cout << result;
}