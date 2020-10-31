#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int maxN = -1;
int MAP[501][501] = { 0, };
bool v[501][501] = { false, };
int picture = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> MAP[i][j];
	}
}
// 도화지 넓이반환
int bfs(int i, int j)
{
	if (v[i][j] == true || MAP[i][j] == 0)
		return 0;
	++picture;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	v[i][j] = true;
	int count = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < N && 0 <= newY && newY < M && v[newX][newY] == false && MAP[newX][newY] == 1)
			{
				++count;
				v[newX][newY] = true;
				q.push(make_pair(newX, newY));

			}
		}
		
	}
	return  count;
}

void Solution()
{
	Input();
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int result = bfs(i, j);
			if (maxN < result)
				maxN = result;
		}
	}
	cout << picture<<'\n'<<maxN;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solution();
	return 0;
}