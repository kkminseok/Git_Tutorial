#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool check[1001] = { false, };
vector<int>* vec;
int bfs(int start)
{
	if (check[start] == true)
		return 0;
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < vec[x].size(); ++i)
		{
			int y = vec[x][i];
			if (!check[y])
			{
				q.push(y);
				check[y] = true;
			}
		}
	}
	return 1;
}

int main()
{
	int n, m;
	cin >> n>>m;

	vec = new vector<int>[n + 1];
	
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int result = 0;
	for (int i = 1; i <= n; ++i)
	{
		result +=bfs(i);
 	}
	cout << result;
	delete[]vec;

}