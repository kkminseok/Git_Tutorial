#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
const int max = 100001;


std::vector<int>* vec;
bool check[max] = { false ,};
int parent[max];


void bfs()
{
	std::queue<int> q;
	q.push(1);
	check[1] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int nx : vec[x])
		{
			if (!check[nx])
			{
				parent[nx] = x;
				q.push(nx);
				check[nx] = true;
			}
		}
		
		
	}
}
int main()
{
	using namespace std;

	int n;
	scanf("%d", &n);
	vec = new vector<int>[n + 1];
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	bfs();
	for (int i = 2; i <= n; ++i)
		cout << parent[i] << '\n';
	delete[] vec;
}