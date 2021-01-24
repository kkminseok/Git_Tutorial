#include<queue>
#include<iostream>

using namespace std;

const int MAX = 101;
int MAP[MAX][MAX] = { 0, };
long long DP[MAX][MAX] = { 0, };
int N;
void Input()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> MAP[i][j];
	}
}

void Solve()
{
	DP[0][0] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (DP[i][j] == 0 || (i == N - 1 && j == N - 1))
				continue;
			else
			{
				int lange = MAP[i][j];
				int newX = i + lange;
				int newY = j + lange;
				if (newX < N) DP[newX][j] += DP[i][j];
				if (newY < N) DP[i][newY] += DP[i][j];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
	cout << DP[N - 1][N - 1];

	return 0;
}