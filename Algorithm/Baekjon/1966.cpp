#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>


int main()
{
	using namespace std;
	int t,n,m;
	int index = 0;
	scanf("%d", &t);
	getchar();
	int arr[10] = { 0, };
	int count = 9;
	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d", &n, &m);
		getchar();
		int count = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int j = 0; j < n; ++j)
		{
			int val;
			scanf("%d", &val);
			q.push({ j,val });
			pq.push(val);
		}

		while (!q.empty())
		{
			int currentidx = q.front().first;
			int currentval = q.front().second;
			q.pop();
			if (pq.top() == currentval)
			{
				pq.pop();
				count++;

				if (currentidx == m)
				{
					cout << count <<endl;
					break;
				}
			}
			else
			{
				q.push({ currentidx,currentval });
			}
		}
	}


	return 0;
}