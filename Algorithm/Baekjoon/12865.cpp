#include<iostream>
#include<algorithm>

using namespace std;

int n, k;

class bag
{
public:
	int w;
	int v;
};

bag arr[101];
int dp[101][100002];

void Input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i].w;
		cin >> arr[i].v;
	}

}

void Solve()
{
	int result = 0;
	for (int i = 1; i <= n; ++i)
	{
		int weight = arr[i].w;
		int val = arr[i].v;
		for (int j = 0; j <= k; ++j)
		{
			if (j < weight)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - weight] + val);
		}
	}
	cout << dp[n][k];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i].w;
		cout << arr[i].v<<'\n';
	}
	
	
	Solve();

	return 0;
}