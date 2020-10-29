#include<iostream>
#include<queue>
using namespace std;

const int MAX = 101;
int N, M,K;
bool Map[MAX][MAX] = { false };
bool v[MAX][MAX] = { false };
int maxN = -1;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int r, c;
		cin >> r >> c;
		Map[r][c] = true;
	}
}

int bfs(int i, int j)
{
	if (Map[i][j] != true)
		return 0;
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	
	int trash = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < N+1 && 0 <= newY && newY < M+1 && v[newX][newY] == false && Map[newX][newY] == true)
			{
				v[newX][newY] = true;
				++trash;
				q.push(make_pair(newX, newY));
			}
		}
	}
	return trash;

}

void Solution()
{
	Input();
	//순차적으로 bfs수행
	for (int i = 1; i < N+1; ++i)
	{
		for (int j = 1; j < M+1; ++j)
		{
			int temp = bfs(i, j);
			if (temp > maxN)
				maxN = temp;
		}
	}
	cout << maxN;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}