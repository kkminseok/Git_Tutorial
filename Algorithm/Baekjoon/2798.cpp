#include<iostream>
#include<algorithm>
using namespace std;

void Solution()
{
	int n, m;
	cin >> n >> m;
	int* card = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> card[i];
	sort(card, card + n);
	int result = 0;
	int count = 0;
	int max = 0;
	for (int i = 0; i <= n-2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n - 2; ++k)
			{
				result = card[i] + card[j] + card[k];
				if (result > max && result < m)
					max = result;
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
	return 0;
}