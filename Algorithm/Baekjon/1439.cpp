#include<iostream>
#include<string>
int main()
{
	using namespace std;
	string input;
	cin >> input;
	int i = 0;
	int count1 = 0;//0을 경계
	int count2 = 0;//1를 경계
	while (i < input.size())
	{
		if (input[i] == '0')
		{
			++count1;
			while (input[i + 1] == '0')
				++i;
		}
		else
		{
			++count2;
			while (input[i + 1] == '1')
				++i;
		}
		++i;
	}
	count1 < count2 ? cout << count1 : cout << count2;
}