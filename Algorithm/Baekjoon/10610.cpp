#include<iostream>
#include<string>
#include<algorithm>
bool checknum(std::string input)
{
	int index = 0;
	while (input[index] != '\0')
	{
		if (input[index] == '0')
			return true;
		++index;
	}
	return false;
}
bool checkThree(std::string input)
{
	int sum = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		sum += input[i]-48;
	}
	if (sum % 3 == 0)
		return true;
	return false;
}
bool desc(int a, int b)
{
	return a > b;
}
int main()
{
	using namespace std;

	string input;
	int strsize = 0;
	cin >> input;
	strsize = input.size();
	//0이 들어있는지, 자리수 합이 3의 배수인지
	if (checknum(input) && checkThree(input))
	{
		int* arr = new int[strsize+1];
		int index = 0;
		for (int i = 0; i < strsize; ++i)
		{
			arr[i] = input[i] - 48;
		}
		sort(arr, arr + strsize,desc);
		for (int i = 0; i < strsize; ++i)
		{
			cout << arr[i];
		}
		delete arr;
	}
	else
	{
		cout << -1;
	}
	
	return 0;

}
