#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int L, R, C;
char MAP[31][31][31] = { '0', };
bool v[31][31][31] = { false };

int startz = 0;
int startx = 0;
int starty = 0;

int dx[6] = { -1,0,1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

bool Input()
{
	scanf("%d %d %d", &L, &R, &C);
	
	if (L==0 &&R==0&&C ==0)
		return false;
	getchar();
	for (int i = 0; i < L; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			for (int k = 0; k < C; ++k)
			{
				scanf("%1c", &MAP[i][j][k]);
				if (MAP[i][j][k] == 'S')
				{
					startz = i;
					startx = j;
					starty = k;
				}
			}
			getchar();
		}
		getchar();
	}
	return true;
}

int Solve()
{
	queue<pair<pair<int, int>,pair<int, int>>> q;
	q.push(make_pair(make_pair(startz, startx), make_pair(starty,0)));
	v[startz][startx][starty] = true;
	while (!q.empty())
	{
		int z = q.front().first.first;
		int x = q.front().first.second;
		int y = q.front().second.first;
		int count = q.front().second.second;
		q.pop();
		if (MAP[z][x][y] == 'E')
			return count;
		for (int k = 0; k < 6; ++k)
		{
			int newZ = z + dz[k];
			int newX = x + dx[k];
			int newY = y + dy[k];

			if (0 <= newZ && newZ < L && 0 <= newX && newX < R && 0 <= newY && newY < C && v[newZ][newX][newY] == false && MAP[newZ][newX][newY] != '#')
			{
				q.push(make_pair(make_pair(newZ, newX), make_pair(newY, count + 1)));
				v[newZ][newX][newY] = true;
			}
		}
	}
	return 0;
}

int main() {
	while (Input())
	{

		int result = Solve();
		if (result == 0)
		{
			printf("Trapped!\n");
		}
		else
		{
			printf("Escaped in %d minute(s)\n", result);
		}
		memset(v, false, sizeof(v));
		memset(MAP, false, sizeof(MAP));
	}


	return 0;
}