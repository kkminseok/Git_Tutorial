#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MAX = 100001;

int n, k;
int v[MAX];

void Input()
{
	cin >> n >> k;
	for (int i = 0; i < MAX; ++i)
	{
		v[i] = 100000;
	}
}

int Solve()
{
	//Bfs
	queue<int> q;
	q.push(n);
	v[n] = 0;
	while (!q.empty())
	{
		int spot = q.front();
		q.pop();
		if (spot == k)
			return v[spot];
		if (spot + 1 < MAX && v[spot + 1] > v[spot])
		{
			q.push(spot + 1);
			v[spot + 1] = v[spot] + 1;
		}
		if (spot - 1 >= 0 && v[spot - 1] > v[spot])
		{
			q.push(spot - 1);
			v[spot - 1] = v[spot] + 1;
		}
		if (spot * 2 < MAX && v[spot * 2] > v[spot])
		{
			q.push(spot * 2);
			v[spot * 2] = v[spot];
		}
			
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	cout<<Solve();
	

	return 0;
}