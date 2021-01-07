#include<iostream>

using namespace std;

int MAP[2200][2200];
int n;
int result[3] = { 0,0,0 };
void Input()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> MAP[i][j];
	}
}
bool check(int i, int j,int size)
{
	int start = MAP[i][j];
	for (int row = i; row < i + size; ++row)
	{
		for (int col = j; col < j + size; ++col)
		{
			if (start != MAP[row][col])
				return false;
		}
	}
	return true;
}

void divide(int i, int j,int size)
{
	if (check(i, j, size))
		result[MAP[i][j] + 1]++;
	else
	{
		int div = size / 3;
		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
				divide(i + row * div, j + col * div, div);
		}
	}
}

void Solve()
{
	divide(0, 0,n);
	cout << result[0] << '\n' << result[1] << '\n' << result[2] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Input();
	Solve();
	return 0;
}