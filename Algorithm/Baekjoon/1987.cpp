#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 22;
int r, c;

int result = 1;
char MAP[MAX][MAX] = { '0', };
bool check[30] = { false, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1};


void DFS(int i, int j,int count)
{
	result = max(result, count);
	check[MAP[i][j] - 65] = true;
	for (int k = 0; k < 4; ++k)
	{
		int newX = i + dx[k];
		int newY = j + dy[k];
		if (0 <= newX && newX < r && 0 <= newY && newY < c && !check[MAP[newX][newY]-65])
		{
			DFS(newX, newY,count+1);
			check[MAP[newX][newY] - 65] = false;	
		}
	}

}

void Input()
{
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		cin>>MAP[i];
	}

}

void Solve()
{
	memset(check, false, sizeof(check));
	DFS(0, 0,1);
	
	cout << result;


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solve();
}