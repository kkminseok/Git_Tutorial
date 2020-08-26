#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

int main()
{
	using namespace std;
	int n, k;
	cin.tie();
	cin >> n >> k;
	vector<int> bag(k);
	vector<pair<int, int>> jewel(n);
	long long result = 0LL;
	priority_queue<int> pq;

	for (int i = 0; i < n; ++i)
	{
		int m, v;
		cin >> m >> v;
		jewel[i] = make_pair(m, v);
	}
	for (int i = 0; i < k; ++i)
		cin >> bag[i];

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	for (int i = 0, jewel_index = 0; i < k; ++i)
	{
		while (jewel_index < n && jewel[jewel_index].first <= bag[i])
			pq.push(jewel[jewel_index++].second);
		if (!pq.empty())
		{
			result += (long long)pq.top();
			pq.pop();
		}
	}
	cout << result;
}
