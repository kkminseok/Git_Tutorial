#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int F, S, G, U, D;


void Input()
{
	cin >> F >> S >> G >> U >> D;
}
int Solve()
{
	//BFS
	bool* v = new bool[F + 1];
	memset(v, false, sizeof(bool) * (F + 1));
	queue<pair<int,int>> q;
	q.push(make_pair(S,0));
	v[S] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == G)
		{
			delete v;
			return cnt;
		}
		if (x+U <= F && !v[x + U])
		{
			v[x + U] = true;
			q.push(make_pair(x + U,cnt+1));
		}
		if (x-D >=0 && !v[x - D])
		{
			v[x - D] = true;
			q.push(make_pair(x - D,cnt+1));
		}
	}
	delete v;
	return -1;

	
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	int result = Solve();
	if (result == -1)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << result;
	}

	return 0;
}