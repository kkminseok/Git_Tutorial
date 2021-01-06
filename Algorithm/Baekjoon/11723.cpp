#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool v[21] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string query;
		int temp = 0;
		cin >> query;
		if (query.compare("all") && query.compare("empty"))// all이나 empty아닌 경우
			cin >> temp;
		if (!query.compare("add"))
			v[temp] = true;
		else if (!query.compare("remove"))
			v[temp] = false;
		else if (!query.compare("check"))
		{
			cout << v[temp] << '\n';
		}
		else if (!query.compare("toggle"))
		{
			v[temp] = !v[temp];
		}
		else if (!query.compare("all"))
			memset(v, true, sizeof(v));
		else if (!query.compare("empty"))
			memset(v, false, sizeof(v));
			
	}
	
	return 0;
}