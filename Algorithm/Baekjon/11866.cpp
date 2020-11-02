#include<iostream>
#include<deque>
using namespace std;

void q_pop(deque<int> q,int n,int k)
{
	while (!q.empty())
	{
		for (int i = 1; i < k; ++i)
		{
			int temp = q.front();
			q.pop_front();
			q.push_back(temp);
		}
		if (!q.empty())
		{
			if (q.size() == 1)
				cout << q.front();
			else
				cout << q.front() << ", ";
			q.pop_front();
		}
	}
	
}

void Solution()
{
	int n, k;
	cin >> n >> k;
	deque<int> q;
	for (int i = 1; i <= n; ++i)
		q.push_back(i);
	cout << "<";
	q_pop(q,n, k);
	cout << ">";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
	return 0;
}