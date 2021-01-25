#include<iostream>

using namespace std;
const int MAX = 100002;
int DP[MAX][4] = { 0, };

void printDP(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cout << DP[i][j] << " ";
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	DP[1][0] = 1;
	DP[1][1] = 1;
	DP[1][2] = 1;
	for (int i = 2; i <= n; ++i)
	{
		//경우 1 미배치 하는 경우
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 9901;
		//경우 2 왼쪽 칸에 사자를 배치할 경우
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % 9901;
		//경우 3 오른쪽 칸에 사자를 배치할 경우
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % 9901;
	}
	cout << (DP[n][0] + DP[n][1] + DP[n][2])%9901;
}
