#include<iostream>
using namespace std;

void Solution()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* dp = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int max = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (dp[i - 1] + arr[i] > arr[i])
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
		if (dp[i] > max)
			max = dp[i];
	}
	cout << max;



}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}