#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int N;
vector<int>* vec;
int dp[51] = { 0 };
bool v[51] = { false, };
int result[51] = { 0, };

void Input()
{
	cin >> N;
	vec = new vector<int>[N + 1];
	int u, v;
	while (1)
	{
		cin >> u >> v;
		if (u == -1 && v == -1)
			break;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	v[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < vec[x].size(); ++i)
		{
			if (v[vec[x][i]] != true)
			{
				q.push(vec[x][i]);
				v[vec[x][i]] = true;
				dp[vec[x][i]] = dp[x]+1;
			}
		}
		
	}
	int maxZ = -1;
	for (int i = 1; i <= N; ++i)
	{
		if (maxZ < dp[i])
			maxZ = dp[i];
	}
	result[start] = maxZ;
}
void Solution()
{
	Input();
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; ++i)
	{
		memset(v, false, sizeof(v));
		memset(dp, 0, sizeof(int)*(N+1));
		bfs(i);
	}
	int minZ = 52;
	for (int i = 1; i <= N; ++i)
	{
		if (minZ > result[i])
			minZ = result[i];
	}
	int count = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (result[i] == minZ)
			++count;
	}
	cout << minZ << " " << count << '\n';
	for (int i = 1; i <= N; ++i)
	{
		if (result[i] == minZ)
			cout << i << " ";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution();
	
	return 0;
	
}