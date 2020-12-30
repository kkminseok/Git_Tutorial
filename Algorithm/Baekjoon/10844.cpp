#include<iostream>

using namespace std;

const int row = 101;
const int col = 11;
int result[row][col] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	long long count = 9;
	for (int i = 1; i < 10; ++i)
		result[1][i] = 1;
	for (int i = 2; i <= n; ++i)
	{
		count = 0;
		result[i][0] += result[i - 1][1];
		count += result[i][0];
		for (int j = 1; j < 10; ++j)
		{
			result[i][j] = (result[i - 1][j - 1] + result[i - 1][j + 1])%1000000000;
//			cout << j << " " << result[i][j] << '\n';
			count += result[i][j];
		}
	}
	cout << count% 1000000000;
}