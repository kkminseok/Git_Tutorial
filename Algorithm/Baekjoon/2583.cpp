#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int MAX = 100;

bool arr[MAX][MAX] = { false };
bool v[MAX][MAX] = { false };
int N, M, K;
int Rcount = 0;
vector<int> area;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


void makeRectangle(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i < x2; ++i)
	{
		for (int j = y1; j < y2; ++j)
			arr[j][i] = true;
	}
}

void bfs(int i, int j)
{
	if (arr[i][j] == true)//사각형 범위일경우
		return;
	else if (v[i][j] == true)//이미 들린 경우
		return;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	v[i][j] = true;
	++Rcount;
	int areanum = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int newX = x + dx[k];
			int newY = y + dy[k];
			if (0 <= newX && newX < N && 0 <= newY && newY < M && arr[newX][newY] == false && v[newX][newY] == false)
			{
				q.push(make_pair(newX, newY));
				v[newX][newY] = true;
				++areanum;
			}
		}

	}
	area.push_back(areanum);
	

}

void Solve()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			bfs(i, j);
		}
	}
	cout << Rcount<<'\n';
	sort(area.begin(), area.end());
	vector<int>::iterator it;

	for (it = area.begin(); it != area.end(); ++it)
	{
		cout << *it << " ";
	}
}
void Input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		makeRectangle(x1, y1, x2, y2);
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();

	return 0;
}