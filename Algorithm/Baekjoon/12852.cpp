#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int* dp;
const int MAX = 1000001;
int n;

void dpbfs()
{
	dp[1] = 1;
	dp[2] = 2;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		//3곱
		if (x * 3 < n+1 && dp[x*3]==0)
		{
			dp[x * 3] = dp[x] + 1;
			q.push(x * 3);
		}
		//2곱
		if (x * 2 < n+1 && dp[x * 2] == 0)
		{
			dp[x * 2] = dp[x] + 1;
			q.push(x * 2);
		}
		if (x + 1 < n+1 && dp[x + 1] == 0)
		{
			dp[x + 1] = dp[x] + 1;
			q.push(x + 1);
		}
		q.pop();
		
	}
}

void Solution()
{
	cin >> n;
	//dp를 위한 동적할당
	dp = new int[n+1];
	memset(dp, 0, sizeof(int) * (n+1));
	dpbfs();
	//역추적
	int temp = n;
	int tempindex = dp[n];
	cout << tempindex << '\n';
	cout << temp << " ";
	while (temp != 1)
	{
		if (dp[temp / 3] == tempindex - 1 && temp%3==0)
			temp /= 3;
		else if (dp[temp / 2] == tempindex - 1 && temp%2==0)
			temp /=2;
		else if (dp[temp - 1] == tempindex - 1)
			temp -= 1;
		tempindex--;
		cout << temp << " ";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}