#include<iostream>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;
	int n, k;
	
	cin >> n >> k;
	int temp = 1;
	int input = 0;
	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}
	cout << '<';
	while (!q.empty())
	{
		if (temp == k)
		{
			temp = 0;
			input = q.front();
			q.pop();
			if (q.size() != 0)
				cout << input << ", ";
			else
				cout << input;
		}
		else
		{
			input = q.front();
			q.pop();
			q.push(input);
		}
		++temp;
	}
	cout << '>';

	return 0;
}