#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int N, M;
int counting[10001] = { 0, };
int maxz = -1;

bool v[100001] = { false };
void bfs(int start,vector<int> graph[])
{
	queue<int> q;
	q.push(start);
	v[start] = true;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < graph[tmp].size(); ++i)
		{
			if (v[graph[tmp][i]] == false)
			{
				q.push(graph[tmp][i]);
				++counting[start];
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	int a,b;
	vector<int>* graph = new vector<int>[N + 1];
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i)
	{
		memset(v, false, sizeof(v));
		bfs(i,graph);
		if (maxz < counting[i])
			maxz = counting[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		if (maxz == counting[i])
			cout << i<<" ";
	}
}