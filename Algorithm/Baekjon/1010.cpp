#include<iostream>
using namespace std;

int dp[31][31] = { 0, };

int ncm(int x,int y)
{
	if (dp[x][y] != 0)
		return dp[x][y];
	if (x == y || y == 0)
		return 1;
	else
		return dp[x][y] = ncm(x-1,y-1) + ncm(x-1,y);
}

void Solution()
{
	dp[1][1] = 1;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int x, y;
		cin >> x >> y;
		cout << ncm(y, x) << '\n';
	}
	
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solution();
}