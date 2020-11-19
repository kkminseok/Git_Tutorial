#include<iostream>
#include<climits>
using namespace std;

int MAP[501][501] = { 0, };
int dp[257] = { 0, };
int N, M,B;
int minN = INT_MAX;
int maxN = INT_MIN;
void Input()
{
	cin >> N >> M >> B;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> MAP[i][j];
			if (minN > MAP[i][j])
				minN = MAP[i][j];
			if (maxN < MAP[i][j])
				maxN = MAP[i][j];
		}
	}
}

void search(int i)
{
	int hour = 0;
	int block = B;
	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < M; ++y)
		{
			if (MAP[x][y] != i)
			{
				if (MAP[x][y] > i)
				{
					//더 크면 파야됨.
					hour += (2 *(MAP[x][y]-i));
					block += (1 * (MAP[x][y]-i));
				}
			}
		}
	}
	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < M; ++y)
		{
			if (MAP[x][y] < i)
			{
				//작은 경우는 쌓되, block이 딸리면 불가능한 것.
				if (block >= i - MAP[x][y])
				{
					block -= (i - MAP[x][y]);
					hour += (1 * (i-MAP[x][y]));
				}
				else
				{
					//불가능
					return;
				}
			}
		}
	}
	dp[i] = hour;
	
}
void Solution()
{
	Input();
	int result;
	int index = 0;
	for (int i = minN; i <= maxN; ++i)
	{
		search(i);
	}
	if (minN == maxN)
	{
		result = 0; index = minN;
	}
	else
		result = INT_MAX;
	
	for (int i = maxN; i >= 0; --i)
	{
		if (result > dp[i])
		{
			if (dp[i] == 0 || i < minN)
				continue;
			result = dp[i];
			index = i;
		}
	}
	cout <<result<<" "<<index;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}