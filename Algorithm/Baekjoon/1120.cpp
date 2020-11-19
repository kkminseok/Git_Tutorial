#include<algorithm>
#include<iostream>
#include<string>
int main()
{
	using namespace std;

	string input1, input2,reversestr1,reversestr2;
	cin >> input1 >> input2;
	int count = 0;
	int min = 51;
	int result = 0;
	for (size_t i = 0; i <= input2.size()-input1.size(); ++i)
	{
		for (int j = 0; j < input1.size(); ++j)
		{
			if (input1[j] != input2[j + count])
				result++;

		}
		if (result < min)
			min = result;
		++count;
		result = 0;
	}
	cout << min;
	


}