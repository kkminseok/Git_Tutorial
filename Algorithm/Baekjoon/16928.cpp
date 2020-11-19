#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAX = 101;
int n, m;
int d[MAX] = { 0, };
int MAP[MAX] = { 0, };

void Input()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		MAP[x] = y;
	}
	for (int i = 0; i <m; ++i)
	{
		int x, y;
		cin >> x >> y;
		MAP[x] = y;
	}

}
void printMAP()
{
	for (int i = 0; i < 100; ++i)
	{
		if (i % 10 == 0)
			cout << '\n';
		cout << MAP[i] << " ";
	}
}


void BFS()
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i)
		{
			int newX = x + i;
			if (newX > 101)
				continue;
			if (MAP[newX] != 0)
			{
				newX = MAP[newX];
				
			}
			if (d[newX] == 0)
			{
				d[newX] = d[x] + 1;
				q.push(newX);
			}
			
		}
	}
	
}

void Solution()
{
	
	Input();
	printMAP();
	BFS();
	cout << d[100];
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}