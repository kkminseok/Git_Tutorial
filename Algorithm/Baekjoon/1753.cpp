#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 20010;
int V,E;
int current;
vector<pair<int, int>> v[MAX];
int di[MAX];

void Input()
{
	int start, end, weight;
	
	
	cin >> V >> E;
	cin >> current;
	for (int i = 0; i < E; ++i)
	{
		cin >> start >> end >> weight;
		v[start].push_back(make_pair(weight, end));
	}
	for (int i = 1; i <= V; ++i)
		di[i] = INF;

}

void dijkstra(int start)
{
	di[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0,start));

	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (di[curr] < distance) continue;
		for (int i = 0; i < v[curr].size(); ++i)
		{
			int next = v[curr][i].first;
			int nextDistance = v[curr][i].second+distance;
			if (nextDistance < di[next])
			{
				di[next] = nextDistance;
				pq.push(make_pair(-nextDistance,next));
			}
		}

	}
}

void Solve()
{
	//다익스트라
	dijkstra(current);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
	for (int i = 1; i <= V; ++i)
	{
		if (di[i] != INF)
			cout << di[i] << '\n';
		else
			cout << "INF\n";
	}
	return 0;
}