#include<iostream>
#include <queue>
#include<cstring>
using namespace std;

const int MAX = 501;

int N, M;
int MAP[MAX][MAX] = { 0, };
int dp[MAX][MAX];

int dx[4] = { -1, 0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> MAP[i][j];
			dp[i][j] = 0;
		}
	}

}

int DFS(int i, int j)
{
	if (i == N - 1 && j == M - 1)
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = 0;
	for (int k = 0; k < 4; ++k)
	{
		int newx = i + dx[k];
		int newy = j + dy[k];
		if (0 <= newx && newx < N && 0 <= newy && newy < M && MAP[newx][newy] < MAP[i][j])
		{
			dp[i][j] += DFS(newx, newy);
		}
	}
	return dp[i][j];
}

void Solve()
{
	//DFS
	memset(dp, -1, sizeof(dp));
	cout << DFS(0, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
}

