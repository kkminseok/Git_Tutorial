#include<string>
#include<iostream>

int main()
{
	using namespace std;

	string input;
	cin >> input;
	int arr[26] = { 0, };
	for (int i = 0; i < input.size(); ++i)
	{
		arr[input[i] - 97]++;
	}
	for (int i = 0; i < 26; ++i)
		cout << arr[i] << " ";
}