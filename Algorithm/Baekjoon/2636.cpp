#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 101;

int row, col;
int MAP[MAX][MAX] = { };
bool v[MAX][MAX] = { false };

int result = 0;
int Ccount = 0;
int day = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//없어도됨.
void print()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cout << MAP[i][j]<<" ";
		cout << '\n';
	}
}

void Input()
{
	cin >>row>>col;
	
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
				++Ccount;
		}
	}
}

void Solve()
{
	queue<pair<int, int>> q;
	
	while (Ccount != 0)
	{
		day++;
		result = Ccount;
		memset(v, false, sizeof(v));
		q.push(make_pair(0, 0));
		while (!q.empty())
		{
			int airx = q.front().first;
			int airy = q.front().second;
			q.pop();
			for (int k = 0; k < 4; ++k)
			{
				int newAx = airx + dx[k];
				int newAy = airy + dy[k];
				if (0 <= newAx && newAx < row && 0 <= newAy && newAy < col && v[newAx][newAy]==false)
				{
					if (MAP[newAx][newAy] == 1)//치즈인경우
					{
						MAP[newAx][newAy] = 0;
						--Ccount;
					}
					else //공기인경우
						q.push(make_pair(newAx, newAy));
					v[newAx][newAy] = true;
				}
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
	cout << day << '\n' << result << '\n';
}