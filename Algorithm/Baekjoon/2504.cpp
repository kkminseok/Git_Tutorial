#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	cin >> str;
	long long result = 0;
	stack<char> s;
	int temp = 1;

	for (unsigned int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
			temp *= 2;
		}
		else if (str[i] == '[')
		{
			s.push(str[i]);;
			temp *= 3;
		}
		else if (str[i] == ')')
		{
			if (s.size() == 0 || s.top() == '[')
			{
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(')
				result += temp;
			temp /= 2;
			s.pop();
			
		}
		else if (str[i] == ']')
		{
			if (s.size() == 0 || s.top() == '(')
			{
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[')
				result += temp;
			temp /= 3;
			s.pop();
		}
	}
	cout << result;
	
	return 0;
}