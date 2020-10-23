#include<queue>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int result1 = 0;
int result2 = 0;
string arr[25];
bool v[25][25] = { false, };

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int c = 0;
bool bfs(int i, int j,char check)
{
	int count = 0;
	if (v[i][j] == true || arr[i][j]!= check)
	{
		return false;
	}
	v[i][j] = true;
	queue < pair<int, int>> q;
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
			if (0 <= newX && newX < n && 0 <= newY && newY < n && arr[newY][newX] == check && v[newY][newX] == false)
			{
				++count;
				v[newY][newX] = true;
				q.push(make_pair(newY, newX));
			}
		}
	}
	return true;
}
bool bfs2(int i, int j, char check)
{

	int count = 0;
	if (v[i][j] == true || arr[i][j] != check)
	{
		return false;
	}
	v[i][j] = true;
	queue < pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		if (check == 'G' || check == 'R')
		{
			for (int k = 0; k < 4; ++k)
			{
				int newY = y + dy[k];
				int newX = x + dx[k];
				if (0 <= newX && newX < n && 0 <= newY && newY < n && (arr[newY][newX] == 'R' || arr[newY][newX] == 'G') && v[newY][newX] == false)
				{
					++count;
					v[newY][newX] = true;
					q.push(make_pair(newY, newX));
				}
			}
		}
		else
		{
			for (int k = 0; k < 4; ++k)
			{
				int newY = y + dy[k];
				int newX = x + dx[k];
				if (0 <= newX && newX < n && 0 <= newY && newY < n && arr[newY][newX] == 'B' && v[newY][newX] == false)
				{
					++count;
					v[newY][newX] = true;
					q.push(make_pair(newY, newX));
				}
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	//일반 사람
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (bfs(i, j, 'R'))
			{
				++result1;
			}
			else if (bfs(i, j, 'G'))
			{
				++result1;
			}
			else if (bfs(i, j, 'B'))
			{
				++result1;
			}
		}
	}
	//색약인 사람
	memset(v, false, sizeof(v));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (bfs2(i, j, 'R'))
			{
				++result2;
			}
			else if (bfs2(i, j, 'G'))
			{
				++result2;
			}
			else if (bfs2(i, j, 'B'))
			{
				++result2;
			}
		}
	}

	cout << result1<<" "<<result2<< '\n';
	int k = 0;
}