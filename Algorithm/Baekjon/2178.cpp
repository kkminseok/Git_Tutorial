#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<queue>

using namespace std;

int n, m;
string arr[100];
bool v[100][100] = { false };
int check[100][100] = { 0, };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs(int i, int j)
{
	v[i][j] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newY = y + dy[k];
			int newX = x + dx[k];
			if (0 <= newX && newX < m && 0 <= newY && newY < n && arr[newY][newX] == '1' && v[newY][newX] == false && check[newY][newX] == 0)
			{
				check[newY][newX] = check[y][x] + 1;
				v[newY][newX] = true;
				q.push(make_pair(newY, newX));
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	bfs(0, 0);
	cout << check[n - 1][m - 1] + 1;
}