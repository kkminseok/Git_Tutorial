#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int w, h;
int map[50][50] = { 0, };
bool check[50][50] = { 0, };

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

int bfs(int i, int j)
{
	if (check[i][j] == true || map[i][j] != 1)
		return 0;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	check[i][j] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < h && 0 <= newY && newY < w &&map[newX][newY] == 1 && !check[newX][newY])
			{
				check[newX][newY] = true;
				q.push(make_pair(newX, newY));
			}
		}
	}
	return 1;


}


int main()
{


	while (1)
	{
		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			return 0;
		int result = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
				scanf("%d", &map[i][j]);
		}
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				result += bfs(i, j);
			}
		}
		printf("%d\n", result);
		getchar();
	}



}