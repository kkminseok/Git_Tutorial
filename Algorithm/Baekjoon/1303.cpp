#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
char MAP[101][101];
bool v[101][101] = { false, };
int Wresult = 0;
int Bresult = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Input()
{
	scanf("%d %d", &M, &N);
	getchar();
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			scanf("%1c", &MAP[i][j]);
		getchar();
	}
}
//bfs
int bfs(int i, int j,char color)
{
	if (v[i][j] == true)
		return 0;
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
			if (0 <= newX && newX < N && 0 <= newY && newY < M && v[newX][newY] == false && MAP[newX][newY] ==color)
			{
				v[newX][newY] = true;
				count++;
				q.push(make_pair(newX, newY));
			}
		}
	}
	return count;

}
void Solution()
{
	memset(MAP, ' ', sizeof(MAP));
	Input();
	//bfs¼öÇà
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int temp = bfs(i, j, MAP[i][j]);
			if (MAP[i][j] == 'B')
			{
				Bresult += (temp * temp);
			}
			else
			{
				Wresult += (temp * temp);
			}
		}
	}
	printf("%d %d", Wresult, Bresult);
}

int main()
{

	Solution();
	return 0;
}