#include<iostream>
#include<algorithm>
using namespace std;

int dp[301] = { 0, };

void Solution()
{
	int n;
	cin >> n;
	int* arr = new int[n + 2];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int i = 0;
	dp[0] = arr[0];
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; ++i)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 2] + arr[i - 1]);
	}
	cout << dp[n - 1];
	delete arr;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solution();
}