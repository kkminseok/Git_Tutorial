#include<cstdio>
#include<string>
#include<stack>

using namespace std;

void Solution()
{
	
	while (1)
	{
		stack<char> s;
		bool flag = true;
		string input;
		char temp;
		while ((temp = getchar()) != '.')
		{
			input += temp;
		}
		if (input.size()==0)
		{
			break;
		}
		for (int i = 0; i < input.size(); ++i)
		{
			if (input[i] == '(')
				s.push('(');
			else if (input[i] == '[')
				s.push('[');
			else if (input[i] == ')')
			{
				if (!s.empty() && s.top() == '(')
					s.pop();
				else
				{
					while (!s.empty())
						s.pop();
					puts("no");
					flag = false;
					break;
				}
			}
			else if (input[i] == ']')
			{
				if (!s.empty() && s.top() == '[')
					s.pop();
				else
				{
					while (!s.empty())
						s.pop();
					puts("no");
					flag = false;
					break;
				}
			}
		}
		if (flag && s.empty())
			puts("yes");
		else if (!s.empty())
			puts("no");
		getchar();
	}
}

int main()
{
	Solution();
	return 0;
}