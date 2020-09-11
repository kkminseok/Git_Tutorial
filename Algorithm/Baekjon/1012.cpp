#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;
bool v[51][51] = { false };
int check[51][51] = { 0, };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		v[y][x] = true;
		for (int i = 0; i < 4; ++i)
		{
			int newY = y + dy[i];
			int newX = x + dx[i];
			if (0 <= newY && newY < n &&0<=newX && newX<m&&check[newY][newX] == 1 && v[newY][newX] == false)
			{
				q.push(make_pair(newY, newX));
				v[newY][newX] = true;
			}
		}
	}
	
}
int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	for (int i = 0; i < t; ++i)
	{
		int k;
		scanf("%d %d %d", &m, &n, &k);
		memset(check, 0, sizeof(check));
		memset(v, 0, sizeof(v));
		for (int j = 0; j < k; ++j)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			getchar();
			check[y][x] = 1;
		}

		//bfs
		int result = 0;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (check[j][k] != 0 && v[j][k]==false)
				{
					bfs(j, k);
					++result;
				}
			}
		}
		printf("%d\n", result);
	}
}