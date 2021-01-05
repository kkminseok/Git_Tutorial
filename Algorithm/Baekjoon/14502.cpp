#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 8;

int N, M;
int arr[MAX][MAX];
bool v[MAX][MAX] = { false };
int result = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void printma()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	}
}
void checknum()
{
	result = 0;
	for (int i = 0; i < N; ++i)
	{
		for(int j=0;j<M;++j)
			if (arr[i][j] == 0)
			{
				++result;
			}
	}
	//cout << "result : " << result<<'\n';
}
//바이러스를 퍼트리기 위한
void bfs()
{
	memset(v, false, sizeof(v));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (arr[i][j] == 2)
			{
				q.push(make_pair(i, j));
				v[i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < N && 0 <= newY && newY < M && arr[newX][newY] !=1 && v[newX][newY] != true)
			{
				q.push(make_pair(newX, newY));
				v[newX][newY] = true;
				arr[newX][newY] = 2;
			}
		}
	}
	checknum();
	
}
void make_wall(int x,int y)
{
	int temp[MAX][MAX];
	//복사 해두기
	memcpy(temp, arr, sizeof(arr));
	int wall = 0;
	int wall2 = 0;
	int wall3 = 0;
		for (int i = 0; wall<N; ++i)
		{
			if (i >= M)
			{
				i = 0;
				wall++;
				if (wall >= N)
					break;
			}
			wall2 = wall;
			if (arr[wall][i] != 0)
				continue;
			for (int j = i + 1;wall2<N; ++j)
			{
				if (j >= M)
				{
					j = 0;
					wall2++;
					if (wall2 >= N)
						break;
				}
				wall3 = wall2;
				if (arr[wall2][j] != 0)
					continue;
				
				for (int k = j + 1;wall3<N; ++k)
				{
					if (k >= M)
					{
						k = 0;
						wall3++;
						if (wall3 >= N)
							break;
					}
					if (arr[wall3][k] != 0)
						continue;
					
					arr[wall][i] = 1;
					arr[wall2][j] = 1;
					arr[wall3][k] = 1;
					int resultbefore = result;
					bfs();
					result = max(result, resultbefore);
					//cout << i << j << k << '\n';
					//cout << wall << wall2 << wall3 << '\n';
					//cout << '\n';
					memcpy(arr, temp, sizeof(temp));
				}
				wall3 = wall2;
			}
			wall2 = wall;
		}
}

void Solve()
{
	//input data
	Input();
	//make wall
	make_wall(0, 0);
	cout << result;
	

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();
}