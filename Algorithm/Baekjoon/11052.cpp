#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp[10001];

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> dp[i];

}
void Solve()
{
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = max(dp[i - 1] + dp[1], dp[i]);
		int temp = 1;
		for (int j = 1; j <= i; ++j)
		{
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
		}

		/*
		for (int j = i; j <= n; j =i* temp)
		{
			dp[j] = max(dp[j], dp[i] * temp);
			++temp;
		}
		*/
	}
}
void printdp()
{
	for (int i = 0; i <= n; ++i)
		cout << dp[i] << " ";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
	cout << dp[n];

}