#include<iostream>
#include<algorithm>
using namespace std;

int dp[10001] = { 0, };
int arr[101] = { 0, };
int n, k;

void Input()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
}

void Solve()
{
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = arr[i]; j <= k; ++j)
		{
			if (j - arr[i] >= 0)
				dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k];
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