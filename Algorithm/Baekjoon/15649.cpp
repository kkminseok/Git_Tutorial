#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int arr[9];
bool v[9];

void Input()
{
	cin >> n >> m;
}

void Solve(int cnt) {

	if (cnt == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << '\n';
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			if (!v[i])
			{
				v[i] = true;
				arr[cnt] = i;
				Solve(cnt+1);
				v[i] = false;
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	memset(v, false, sizeof(v));
	Solve(0);
}