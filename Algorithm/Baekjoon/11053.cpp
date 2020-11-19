#include<iostream>
using namespace std;

void Solution()
{
	int n;//n~1000
	cin >> n;
	int* arr = new int[n];
	int* dp = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i] && dp[i] <= dp[j])
			{
				dp[i] += 1;
				if (max < dp[i])
					max = dp[i];
			}
		}
	}
	cout << max;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}