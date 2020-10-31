#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void Solution()
{
	int n, m;
	cin >> n >> m;
	int* trees = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> trees[i];
	sort(trees, trees + n);
	long long left = 0;
	long long right = trees[n-1];
	long long result = 0;
	long long mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		long long total = 0;
		for (int i = n-1; i >= 0; --i)
		{
			if (trees[i] - mid < 0)
				break;
			else
			{
				total += trees[i] - mid;
			}
		}
		if (total >= m)
		{
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}