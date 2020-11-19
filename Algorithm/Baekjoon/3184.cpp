#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;

char map[251][251];
bool check[251][251] = { false };
int r, c;
int wolf=0, sweep=0;

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };

void bfs(int i, int j)
{
	if (check[i][j] == true)
		return;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;
	int subwolf = 0;
	int subsweep = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		if (map[x][y] == 'v')
			++subwolf;
		else if (map[x][y] == 'o')
		{
			++subsweep;
		}

		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];

			if (0 <= newX && newX < r && 0 <= newY && newY < c && !check[newX][newY] && map[newX][newY] != '#')
			{
				q.push(make_pair(newX, newY));
				check[newX][newY] = true;
			}
		}
	}

	if (subwolf >= subsweep)
	{
		sweep -= subsweep;
	}
	else
	{
		wolf -= subwolf;
	}

}

int main()
{
	scanf("%d %d", &r, &c);
	getchar();
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'v')
				++wolf;
			else if (map[i][j] == 'o')
				++sweep;
				
		}
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(map[i][j]!='#')
				bfs(i, j);
		}
	}
	printf("%d %d", sweep, wolf);

}
