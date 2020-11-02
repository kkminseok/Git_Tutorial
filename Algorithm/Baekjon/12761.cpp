#include<iostream>
#include<queue>
using namespace std;

const int MAX = 100001;
int dp[MAX] = { 0, };
int N, M, a, b;

void Input()
{
	cin >> a >> b >> N >> M;
}

void bfs()
{
	queue<int> q;
	q.push(N);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		//8가지 방법 전부 함
		if (x + 1 < MAX && dp[x + 1] == 0)
		{
			dp[x + 1] = dp[x] + 1;
			q.push(x + 1);
		}
		if (x - 1 >= 0 && dp[x - 1] == 0)
		{
			dp[x - 1] = dp[x] + 1;
			q.push(x - 1);
		}
		if (x + a < MAX && dp[x + a] == 0)
		{
			dp[x + a] = dp[x] + 1;
			q.push(x + a);
		}
		if (x - a >= 0 && dp[x - a] == 0)
		{
			dp[x - a] = dp[x] + 1;
			q.push(x - a);
		}
		if (x + b < MAX && dp[x + b] == 0)
		{
			dp[x + b] = dp[x] + 1;
			q.push(x + b);
		}
		if (x - b >= 0 && dp[x - b] == 0)
		{
			dp[x - b] = dp[x] + 1;
			q.push(x - b);
		}
		if (x * a < MAX && dp[x * a] == 0)
		{
			dp[x * a] = dp[x] + 1;
			q.push(x * a);
		}
		if (x * b < MAX && dp[x * b] == 0)
		{
			dp[x * b] = dp[x] + 1;
			q.push(x * b);
		}
	}
}

void Solution()
{
	Input();
	bfs();
	cout << dp[M];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}