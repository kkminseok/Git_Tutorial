#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 101;
int N,M;
vector<int>* vec;
bool v[MAX] = { false, };
int arr[MAX] = { 0, };
//배열에 또 저장
int counting[MAX] = { 0, };
void Input()
{
	cin >> N >> M;
	vec = new vector<int>[N + 1];
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
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
				counting[vec[x][i]] = counting[x] + 1;
				v[vec[x][i]] = true;
				arr[start] += counting[vec[x][i]];
				q.push(vec[x][i]);
			}
		}
	}
}

void Solve()
{
	for (int i = 1; i <= N; ++i)
	{
		memset(v, false, sizeof(v));
		memset(counting, 0, sizeof(counting));
		bfs(i);
	}
	int min = 1000;
	int idx = 1;
	for (int i = 1; i <= N; ++i)
	{
		if (min > arr[i])
		{
			min = arr[i];
			idx = i;
		}
	}
	cout << idx;
}

void solution()
{
	Input();
	Solve();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
