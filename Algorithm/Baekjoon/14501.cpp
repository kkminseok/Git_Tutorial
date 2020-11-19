#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 16;

int dp[MAX] = { 0, };
int t[MAX] = { 0, };
int p[MAX] = { 0, };
void Solution()
{
	int N,result=0;
	cin >> N;
	
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> t[i] >> p[i];
	}
	
	for (int i = 1; i <= N;++i)
	{
		//i번째날 일을 했다.
		if (i + t[i] <= N +1)
		{
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
			result = max(dp[i + t[i]], result);
		}
		//i번째날 일을 안했을 경우
		dp[i + 1] = max(dp[i + 1], dp[i]);
		result = (result, dp[i+1]);
		cout << dp[i] << ' ';
	}

	cout << result;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution();
}