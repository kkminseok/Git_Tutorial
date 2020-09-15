#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

int chess[301][301] = { 0, };
bool check[301][301] = { false, };

int l;

int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int bfs(int x, int y, int dstx, int dsty)
{
	if (x == dstx && y == dsty)
		return 0;
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));

	check[x][y] = true;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (newX == dstx && newY == dsty)
				return chess[x][y] + 1;
			if (0 <= newX && newX < l && 0 <= newY && newY < l && !check[newX][newY])
			{
				q.push(make_pair(newX, newY));
				check[newX][newY] = true;
				chess[newX][newY] = chess[x][y]+1;
			}
		}
	}

	return chess[x][y];
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		memset(chess, 0, sizeof(chess));
		memset(check, false, sizeof(check));
		scanf("%d", &l);
		int x, y;
		scanf("%d %d", &x, &y);
		int dstx, dsty;
		scanf("%d %d", &dstx, &dsty);

		int result = bfs(x, y,dstx,dsty);
		printf("%d\n", result);


	}

}