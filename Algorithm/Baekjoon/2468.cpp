#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N;
const int MAX = 101;
int MAP[MAX][MAX] = { 0, };
bool v[MAX][MAX] = { false };

int maxnum = 0;
int minnum = 200;
int blockcount = 0;// 블락의 갯수
int stageanum = 0;// 영억 갯수
int result = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Input()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> MAP[i][j];
			if (maxnum < MAP[i][j])
				maxnum = MAP[i][j];
			if (minnum > MAP[i][j])
				minnum = MAP[i][j];
		}
	}
}
void water(int high)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (MAP[i][j] ==0)
				continue;
			else
			{
				if (MAP[i][j] <= high)
				{
					MAP[i][j] = 0;
				}
			}
		}
	}
}
void bfs(int i,int j,int high)
{
	if (v[i][j] == true)
		return;
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < N && 0 <= newY && newY < N && MAP[newX][newY] != 0 && v[newX][newY] == false)
			{
				q.push(make_pair(newX, newY));
				blockcount++;
				v[newX][newY] = true;
				if (MAP[newX][newY] == high)
					MAP[newX][newY] = 0;
			}
		}
		
	}

	stageanum++;
}

void Solution()
{
	Input();
	if (minnum == maxnum)
		cout << 1 << '\n';
	else
	{
		for (int k = minnum; k < maxnum; ++k)
		{
			water(k);//초기 침수
			memset(v, false, sizeof(v));
			blockcount = 0;
			stageanum = 0;

			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
					if (MAP[i][j] == 0)
						continue;
					else
						bfs(i, j, k);
			}
			if (stageanum > result)
				result = stageanum;
			/*if (blockcount <= stageanum)
			{
				break;
			}*/
		}
		cout << result << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}