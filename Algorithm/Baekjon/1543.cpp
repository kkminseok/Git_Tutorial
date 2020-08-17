#include<string>
#include<iostream>
#include<algorithm>

int main()
{
	using namespace std;
	string input,result;
	int index = 0;
	int count = 0;
	getline(cin, input);
	getline(cin, result);
	while(input.find(result) != string::npos)
	{
		//Ã£À½
		++count;
		index = input.find(result);
		input = input.substr(index + result.size(),input.size());
	}
	cout << count;
	
	
}