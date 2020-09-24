#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

bool visit[501] = { false };
int result[501] = { 1,1, };
vector<int>* v;

void bfs(int num)
{
	int count = 0;
	queue<int> q;
	q.push(num);
	visit[num] = true;
	while (!q.empty())
	{

		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); ++i)
		{
			if (!visit[v[x][i]])
			{
				visit[v[x][i]] = true;
				result[v[x][i]] = result[x]+1;
				q.push(v[x][i]);
			}
		}

	}

}

int main()
{
	memset(result, 0, sizeof(result));
	int n;//n은 동기 수
	int m;// m은 리스트의 길이
	cin >> n >> m;
	int a, b;
	v = new vector<int>[n + 1];
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;	
		v[a].push_back(b);
		v[b].push_back(a);
	}
	result[1] = 1;
	bfs(1);
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << result[i] << '\n';
	//}
	int count = 0;
	for (int i = 2; i < n + 1; ++i)
	{
		if (result[i] <= 3 && result[i]>1)
		{
			cout << i << result[i]<<'\n';
			++count;
		}
	}
	cout << count;


	delete[] v;
}