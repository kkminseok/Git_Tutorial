#include<iostream>
#include<string>
using namespace std;

//a=97
long long powd(int a, int b)
{
	long long result = 1;
	for (int i = 0; i < b; ++i)
	{
		result = result * 31;
		if (result > 1234567891)
			result %= 1234567891;
	}
	return result;
}
void Solution()
{
	string input;
	int n;
	cin >> n;
	cin >> input;
	long long result = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		result = result + ((input[i] - 96) * powd(31, i));
		result %= 1234567891;
	}
	cout << result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();

	return 0;
}