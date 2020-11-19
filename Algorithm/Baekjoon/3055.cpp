#include<iostream>
#include<queue>
using namespace std;
char MAP[51][51] = { 0, };
int dp[51][51] = { 0, };
bool v[51][51] = { false };
int N, C;
int resultx, resulty;
queue<pair<int, int>> q;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Input()
{
	cin >> N >> C;
	int tempx, tempy;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == '*')
				q.push(make_pair(i, j));
			else if (MAP[i][j] == 'S')
			{
				tempx = i;
				tempy = j;
			}
			else if (MAP[i][j] == 'D')
			{
				resultx = i;
				resulty = j;
			}
			
		}
	}
	q.push(make_pair(tempx, tempy));

}

void bfs()
{
	//*의 위치를 찾아야한다. queue를 두 개 만들면 메모리 초과가 남.
	//queue<pair<int,int>> star;
	//queue<pair<int,int>> Dochi;
	//for (int i = 0; i < N; ++i)
	//{
	//	for (int j = 0; j < C; ++j)
	//	{
	//		if (MAP[i][j] == '*')//물
	//			star.push(make_pair(i, j));
	//		else if (MAP[i][j] == 'S')
	//			Dochi.push(make_pair(i, j));
	//	}
	//}
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (MAP[x][y] == '*')
		{
			//물
			for (int k = 0; k < 4; ++k)
			{
				int newX = x + dx[k];
				int newY = y + dy[k];
				if (0 <= newX && newX < N && 0 <= newY && newY < C && MAP[newX][newY] == '.' && v[newX][newY] == false)
				{
					MAP[newX][newY] = '*';
					q.push(make_pair(newX, newY));
					v[newX][newY] = true;
				}
			}
		}
		else if (MAP[x][y] == '.' || MAP[x][y] == 'S')
		{
			for (int k = 0; k < 4; ++k)
			{
				int newX = x + dx[k];
				int newY = y + dy[k];
				if (MAP[newX][newY] == 'D')
				{
					dp[newX][newY] = dp[x][y] + 1;
					return;
				}
				if (0 <= newX && newX < N && 0 <= newY && newY < C && MAP[newX][newY] == '.' && v[newX][newY] == false)
				{
					MAP[newX][newY] = 'S';
					q.push(make_pair(newX, newY));
					v[newX][newY] = true;
					dp[newX][newY] = dp[x][y] + 1;
				}
			}
		}


		////물부터 작업
		//int starsize = star.size();
		//for (int j = 0; j < starsize; ++j)
		//{
		//	int x = star.front().first;
		//	int y = star.front().second;
		//	star.pop();
		//	for (int k = 0; k < 4; ++k)
		//	{
		//		int newX = x + dx[k];
		//		int newY = y + dy[k];
		//		if (0 <= newX && newX < N && 0 <= newY && newY < C && MAP[newX][newY] == '.' && v[newX][newY] == false)
		//		{
		//			MAP[newX][newY] = '*';
		//			star.push(make_pair(newX, newY));
		//			v[newX][newY] = true;
		//		}
		//	}
		//}

		////고슴도치 작업
		//int Dochisize = Dochi.size();
		//for (int j = 0; j < Dochisize; ++j)
		//{
		//	int x = Dochi.front().first;
		//	int y = Dochi.front().second;
		//	Dochi.pop();
		//	for (int k = 0; k < 4; ++k)
		//	{
		//		int newX = x + dx[k];
		//		int newY = y + dy[k];
		//		if (MAP[newX][newY] == 'D')
		//			return count;
		//		if (0 <= newX && newX < N && 0 <= newY && newY < C && MAP[newX][newY] == '.' && v[newX][newY] == false)
		//		{
		//			MAP[newX][newY] = 'S';
		//			Dochi.push(make_pair(newX, newY));
		//			v[newX][newY] = true;
		//		}
		//	}
		//}
	/*	for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < C; ++j)
				cout << dp[i][j];
			cout << '\n';
		}*/
	}


}

void Solution()
{
	Input();
	bfs();
	if (dp[resultx][resulty] == 0)
		cout << "KAKTUS";
	else
		cout << dp[resultx][resulty];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}