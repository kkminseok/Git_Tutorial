#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>

const int MAX = 51;

char MAP[MAX][MAX] = { '0', };
bool v[MAX][MAX] = { false, };

using namespace std;

int row, col;
int result = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void printarr()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			printf("%c", MAP[i][j]);
		puts("");
	}
}

void Input()
{
	scanf("%d %d", &row, &col);
	getchar();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			scanf("%1c" ,&MAP[i][j]);
		getchar();
	}
}

void BFS(int x, int y)
{
	memset(v, false, sizeof(v));
	queue<pair<pair<int, int>,int>> q;//첫번째와 두번째는 좌표 값, 세번째는 거리

	q.push(make_pair(make_pair(x, y), 0));
	v[x][y] = true;
	int count = 0;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		count = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < row && 0 <= newY && newY < col && v[newX][newY] == false && MAP[newX][newY] == 'L')
			{
				q.push(make_pair(make_pair(newX, newY), count + 1));
				v[newX][newY] = true;
			}
		}
	}
	if (result < count)
		result = count;

}

void Solve()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (MAP[i][j] == 'L')
				BFS(i, j);
		}
	}
	printf("%d", result);
}

int main()
{

	Input();
	Solve();
}