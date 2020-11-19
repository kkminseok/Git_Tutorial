#include<iostream>
#include<string>


int main()
{
	using namespace std;
	
	string input;// 들어올 값.
	int result = 0;
	int arr[100] = { 0, };
	int arrcount = 0;
	char op[100] = { 0, };
	int opcount = 0;
	int index = 0;
	size_t sz;
	cin >> input;// input data

	while (input[index]!='\0')
	{
		if (input[index]!= '+' && input[index] != '-')
		{
			//integer
			arr[arrcount++] = stoi(input,&sz);
			input = input.substr(sz);
		}
		else
		{
			op[opcount++] = input[index];
			input = input.substr(index+1);
		}
	}
	opcount = 0;
	arrcount = 1;
	result = arr[0];//처음 값.
	int minussum = 0;
	while (op[opcount] != '\0')
	{
		if (op[opcount] == '-')
		{
			minussum = arr[arrcount++];
			while (op[++opcount] == '+')
			{
				minussum += arr[arrcount++];
			}
			result -= minussum;
		}
		else
		{
			result += arr[arrcount++];
			opcount++;
		}
	}
	cout << result;
	
}