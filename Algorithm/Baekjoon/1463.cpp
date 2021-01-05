#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

bool* v;

int bfs(int n)
{
	int result = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(n,0));
	v[n] = true;
	while (!q.empty())
	{
		int temp = q.front().first;
		int count = q.front().second;
		if (temp == 1)
			return count;
		q.pop();
		if (temp % 3 == 0 && v[temp/3]==false)//³ª´©¾î ¶³¾îÁü.
		{
			//cout << "3 " << temp<<" " << count << '\n';
			v[temp / 3] = true;
			q.push(make_pair(temp / 3, count+1));
		}
		if (temp % 2 == 0 && v[temp/2]==false)
		{
			//cout << "2 " << temp <<" "<< count << '\n';
			v[temp / 2] = true;
			q.push(make_pair(temp / 2, count+1));
		}
		if (v[temp - 1] == false)
		{
			//cout <<"1 "<< temp<<" "<<count<<'\n';
			v[temp - 1] = true;
			q.push(make_pair(temp - 1, count+1));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	v = new bool[n+1];
	memset(v, false, sizeof(bool) * n+1);
	cout<<bfs(n);

	return 0;
}