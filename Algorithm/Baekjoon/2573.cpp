#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAX = 300;
int N, M;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
bool v[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> MAP[i][j];
	}
}
void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	v[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];

			if (0 <= newX && newX < N && 0 <= newY && newY < M)
			{
				if (v[newX][newY] == false && MAP[newX][newY] != 0)
				{
					v[newX][newY] = true;
					q.push(make_pair(newX, newY));
				}
			}
		}
	}
}

int Melt(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (MAP[newX][newY] == 0)++count;
	}
	return count;
}
void Solution()
{
	int Year = 0;
	while (1)
	{
		int Land = 0;
		memset(v, false, sizeof(v));
		memset(C_MAP, 0, sizeof(C_MAP));

		for (int i = 0 ; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (MAP[i][j] != 0 && v[i][j] == false)
				{
					Land++;
					BFS(i, j);
				}
			}
		}

		if (Land >= 2) { cout << Year << '\n'; break; }
		if (Land == 0) { cout << 0 << '\n'; break; }

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (MAP[i][j] != 0)
				{
					C_MAP[i][j] = MAP[i][j] - Melt(i, j);
					if (C_MAP[i][j] < 0) C_MAP[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				MAP[i][j] = C_MAP[i][j];
			}
		}
		++Year;
	}
}


void Solve()
{
	Input();
	Solution();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}

/*
input :
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
*/