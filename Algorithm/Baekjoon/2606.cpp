#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

int bfs(int start, std::vector<int>graph[], bool check[])
{
	std::queue<int> q;
	int count=0;
	q.push(start);
	check[start] = true;

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		++count;
		for (int i = 0; i < graph[tmp].size(); ++i)
		{
			if (check[graph[tmp][i]] == false)
			{
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
	return count;
}
int main()
{
	using namespace std;
	int n, m;
	cin >> n >> m;

	vector<int>* graph = new vector<int>[n + 1];

	bool* check = new bool[n + 1];
	fill(check, check + n + 1, false);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	int count = bfs(1, graph, check);
	cout << count;
}