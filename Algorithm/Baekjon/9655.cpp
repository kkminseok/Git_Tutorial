#include<iostream>
using namespace std;

void Solution()
{
	int dp[1001] = { 0, };
	int n;
	cin >> n;
	n % 2 == 0 ? cout << "CY" : cout << "SK";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solution();
}