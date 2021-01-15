#include<iostream>
#include<algorithm>
using namespace std;

int dp[10001] = { 0, };
int arr[101] = { 0, };
int n, k;

void dpprint()
{
	for (int i = 0; i <= k; ++i)
	{
		cout << dp[i] << " ";
	}
}

void Input()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	//dp√ ±‚»≠
	for (int i = 0; i <= k; ++i)
	{
		dp[i] = 10001;
	}
}

void Solve()
{
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = arr[i]; j <= k; ++j)
		{	
			if (j - arr[i] > 0)
			{
				if (dp[j - arr[i]] == 0)
					continue;
				else
				{
					dp[j] = min(dp[j - arr[i]] + 1,dp[j]);
				}
			}
			else
				dp[j] = 1;
		}
		//dpprint();
		//cout << '\n';
	}
	if (dp[k] == 10001)
		cout << -1;
	else
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