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
		
		for (int j = 1; j < i; ++j)
		{
			if (arr[j] > arr[i])
			{
				dp[i] = max(dp[i], (dp[j] + 1));
			}
		}
		result = max(dp[i], result);
		
	}
	cout << result+1;
	
	return 0;
}