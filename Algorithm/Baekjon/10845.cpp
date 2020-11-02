#include<iostream>
#include<queue>
#include<string>
using namespace std;

void Solution()
{
	int N;
	cin >> N;
	queue<int> q;
	cin.ignore(256, '\n');
	for (int i = 0; i < N; ++i)
	{
		string input;
		string::size_type n;
		getline(cin, input);
		n = input.find("push");
		if (n!=string::npos)
		{
			//push를 찾은 경우
			n = input.find(" ");
			string temp = input.substr(n, input.size());
			int i = stoi(temp);
			q.push(i);
			continue;
		}
		n = input.find("pop");
		if (n != string::npos)
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				int temp = q.front();
				q.pop();
				cout << temp << '\n';
			}
			continue;
		}
		n = input.find("size");
		if (n != string::npos)
		{
			cout << q.size() << '\n';
			continue;
		}
		n = input.find("empty");
		if (n != string::npos)
		{
			cout << q.empty() << '\n';
			continue;
		}
		n = input.find("front");
		if (n != string::npos)
		{
			if (!q.empty())
				cout << q.front() << '\n';
			else
				cout << "-1\n";
			continue;
		}
		n = input.find("back");
		if (n != string::npos)
		{
			if (!q.empty())
				cout << q.back() << '\n';
			else
				cout << "-1\n";
		}
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();
}