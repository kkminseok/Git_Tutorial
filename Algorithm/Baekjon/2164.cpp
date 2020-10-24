#include<iostream>
#include<queue>
using namespace std;

void Solve()
{
	int n;
	cin >> n;
	
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		q.push(i + 1);
	}
	while (q.size() != 1)
	{
		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solve();
}
/*
input : 6
output : 4
*/