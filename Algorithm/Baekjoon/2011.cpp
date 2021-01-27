#include<iostream>
#include<string>
using namespace std;
int dp[5001][2] = { 0, };

const int MOD = 1000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;
	int countzero = 0;
	if (input[0]-48 == 0 )
	{
		cout << 0;
		return 0;
	}
	dp[0][0] = 1;
	dp[0][1] = 0;
	int numz = 0;
	size_t size = input.size()-1;
	for (size_t i = 1; i < input.size(); ++i)
	{
		if (input[i] - 48 == 0)
		{
			++countzero;
			if (countzero > 1)
			{
				cout << 0;
				return 0;
			}
		}
		else
			countzero = 0;
		
		//2개인 경우
		if (i >= 1)
		{
			if (input[i-1]-48!=0)//두자리 수 가능
			{
				numz = ((input[i - 1] - 48) * 10) +(input[i] - 48);
				if (numz > 0 && numz < 27)
				{
					if (i == 1)
						dp[i][1]++;
					else
						dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
					dp[i][1] %= MOD;
				}
			}
			else
				dp[i][1] = 0;
		}

		//하나인 경우 나중에처리
		if (input[i]-48 != 0)
		{
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][0] %= MOD;
		}
		else
		{
			dp[i][0] = 0;
		}
	}
	cout << (dp[size][0] + dp[size][1])%MOD;
	return 0;
}