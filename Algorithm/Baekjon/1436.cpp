#include<iostream>
#include<string>
using namespace std;

void Solution()
{
	int n;
	cin >> n;
	int count = 0;
	int  i = 666;
	while (count!=n)
	{
		string str = to_string(i);
		if (str.find("666")!=-1)
		{
			//cout << str << '\n';
			++i;
			++count;
		}
		else
		{
			++i;
		}
	}
	cout << i-1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solution();
}
/*
input : 2
output : 1666
*/