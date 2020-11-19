#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>

using namespace std;

int n, m;
bool v[1001][1001] = { false };
int check[1001][1001] = { -1, };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
	queue<pair<int, int>> q;
	int day = 0;
	scanf("%d %d", &m, &n);
	int result = 0;
	getchar();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &check[i][j]);
			if (check[i][j] == 1)
			{
				q.push(make_pair(i, j));
				++day;
			}
		}
	}
	
	int cnt = 0;
	bool traverse = false;
	while (!q.empty())
	{
		cnt = 0;
		traverse = false;
		for (int i = 0; i < day; ++i)
		{
			int x = q.front().second;
			int y = q.front().first;
			q.pop();

			v[y][x] = true;

			for (int k = 0; k < 4; ++k)
			{
				int newY = y + dy[k];
				int newX = x + dx[k];

				if (0 <= newX && newX < m && 0 <= newY && newY < n && check[newY][newX] == 0 && !v[newY][newX])
				{
					traverse = true;
					check[newY][newX] = 1;
					q.push(make_pair(newY, newX));
					++cnt;
				}
			}
		}
		day = cnt;
		traverse == true ? ++result : traverse;

	}
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<m;++j)
			if (!v[i][j] && check[i][j] == 0)
			{
				printf("-1");
				return 0;
			}
	}
	printf("%d\n", result);
}

