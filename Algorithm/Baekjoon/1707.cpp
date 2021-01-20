#include<iostream>
#include<queue>
#include<cstring>

using namespace std;


int map[20001] = {0 };
int t, v, e;

bool BFS(int start, vector<int> vec[])
{
	queue<int> q;
	q.push(start);
	map[start] = 1;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = 0; i < vec[curr].size(); ++i)
		{
			int ver = vec[curr][i];
			//cout << "ver : " << ver << '\n';
			if (map[ver] != 0)//방문기록이 있음.
			{
				if (map[curr] == map[ver])//색이 같다.
				{
					return false;
				}
			}
			else
			{
				q.push(ver);
				map[ver] = 3-map[curr];
			}
		}

	}
	return true;
}

void Input()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		memset(map, 0, sizeof(map));
		bool result=true;
		vector<int> vec[20001];
		cin >> v >> e;
		int first = 0;
		int second = 0;
		for (int j = 0; j < e; ++j)
		{
			cin >> first>>second;
			vec[first].push_back(second);
			vec[second].push_back(first);
		}
		for (int i = 1; i <= v; ++i)
		{
			if (map[i] == 0)
			{
				result = BFS(i, vec);
				if (result == false)
				{
					cout << "NO\n";
					break;
				}
			}
		}
		if (result)
			cout << "YES\n";

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();

	return 0;
}