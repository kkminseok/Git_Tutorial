#include<iostream>
#include<climits>
using namespace std;

void Solution()
{
	int n, k;
	cin >> n >> k;
	int* line = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> line[i];
	}
	long long left = 0;
	long long right = LLONG_MAX;
	long long max = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		int result = 0;
		for (int i = 0; i < n; ++i)
			result += line[i] / mid;
		if (result >= k)
		{
			left = mid + 1;
			if (mid > max)
			{
				max = mid;
			}
		}
		else
		{
			right = mid - 1;
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