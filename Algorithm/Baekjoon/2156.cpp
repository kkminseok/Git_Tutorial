#include<iostream>
#include<algorithm>
using namespace std;
int dp[10003] = { 0, };
int arr[10003] = { 0, };
int n;
int result = 0;
void Solve()
{
	
	for (int i = 3; i < n+3; ++i)
	{
		
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		
		dp[i] = max(dp[i - 1], dp[i]);
		result = max(result, dp[i]);
	}
	for (int i = 3; i < n + 3; ++i)
	{
		cout << dp[i] << ' ';
	}
	cout << result;
}
void Input()
{
	cin >> n;
	for (int i = 3; i < n+3; ++i)
	{
		cin >> arr[i];
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve();

	return 0;
}