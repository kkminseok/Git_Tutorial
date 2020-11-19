#include<string>
#include<iostream>
#include<algorithm>

int main()
{
	using namespace std;
	int n;
	cin >> n;
	int count = 0;
	string str;
	string output = "*";
	int j = 0;
	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		if (output[j] == '*'&& str[i]=='S')
		{
			output += "S*";
		}
		else if(output[j]=='*' && str[i]=='L')
		{
			++i;
			output += "LL*";
		}
	}
	int search = 0;
	for (int i = 0; i < output.size(); ++i)
	{
		if (output[i] == '*')
			++count;
	}
	if (n < count)
		count = n;
	cout << output;
	cout << count;

}